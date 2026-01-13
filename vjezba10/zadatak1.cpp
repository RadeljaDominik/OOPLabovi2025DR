#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    vector<int> v = {1, 3, 4, 7, 8, 10, 12, 16, 21, 32};

    auto it = find_if(v.begin(), v.end(),
                      [](int x) { return x % 2 != 0; });

    if (it != v.end())
        cout << "Prvi neparni broj: " << *it << endl;
    else
        cout << "Nema neparnih brojeva.\n";

    int countOdd = count_if(v.begin(), v.end(),
                            [](int x) { return x % 2 != 0; });

    cout << "Broj neparnih brojeva: " << countOdd << endl;

    int sumOdd = accumulate(v.begin(), v.end(), 0,
        [](int sum, int x) {
            return (x % 2 != 0) ? sum + x : sum;
        });

    if (countOdd > 0) {
        double avg = static_cast<double>(sumOdd) / countOdd;
        cout << "Prosjek neparnih brojeva: " << avg << endl;
    } else {
        cout << "Prosjek neparnih brojeva: 0\n";
    }

    replace_if(v.begin(), v.end(),
               isPowerOfTwo, 2);

    vector<int> even, odd;

    copy_if(v.begin(), v.end(), back_inserter(even),
            [](int x) { return x % 2 == 0; });

    copy_if(v.begin(), v.end(), back_inserter(odd),
            [](int x) { return x % 2 != 0; });

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    cout << "Parni brojevi: ";
    for (int x : even) cout << x << " ";

    cout << "\nNeparni brojevi: ";
    for (int x : odd) cout << x << " ";

    cout << endl;

    return 0;
}

