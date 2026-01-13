#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

namespace student_records {

    class Student {
    public:
        string ime;
        string prezime;
        int bodovi;

        Student() = default;
        Student(const string& i, const string& p, int b)
            : ime(i), prezime(p), bodovi(b) {}
    };

}

istream& operator>>(istream& is, student_records::Student& s) {
    return is >> s.ime >> s.prezime >> s.bodovi;
}

ostream& operator<<(ostream& os, const student_records::Student& s) {
    return os << s.ime << " " << s.prezime
              << " | ocjena: " << s.bodovi;
}

int main() {
    using student_records::Student;

    ifstream file("studenti.txt");
    if (!file) {
        cerr << "Ne mogu otvoriti datoteku studenti.txt\n";
        return 1;
    }

    vector<Student> studenti(
        istream_iterator<Student>(file),
        istream_iterator<Student>()
    );

    auto bodovi_u_ocjenu = [](int bodovi) -> int {
        if (bodovi < 40) return 1;
        if (bodovi < 55) return 2;
        if (bodovi < 70) return 3;
        if (bodovi < 85) return 4;
        return 5;
    };

    studenti.erase(
        remove_if(studenti.begin(), studenti.end(),
            [](const Student& s) {
                return s.bodovi < 40;
            }),
        studenti.end()
    );

    transform(studenti.begin(), studenti.end(), studenti.begin(),
        [&](Student s) {
            s.bodovi = bodovi_u_ocjenu(s.bodovi);
            return s;
        });

    double prosjek = 0.0;
    if (!studenti.empty()) {
        int suma = accumulate(studenti.begin(), studenti.end(), 0,
            [](int acc, const Student& s) {
                return acc + s.bodovi;
            });
        prosjek = static_cast<double>(suma) / studenti.size();
    }

    sort(studenti.begin(), studenti.end(),
        [](const Student& a, const Student& b) {
            return a.prezime < b.prezime;
        });

    cout << "IZVJESTAJ O STUDENTIMA\n";
    cout << "---------------------\n";

    copy(studenti.begin(), studenti.end(),
         ostream_iterator<Student>(cout, "\n"));

    cout << "\nProsjecna ocjena: " << prosjek << endl;

    return 0;
}

