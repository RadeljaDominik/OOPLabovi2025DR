#include <iostream>

using namespace std;

typedef struct {
    string ime;
    string jmbag;
    int studyY;
    int ECTS;
    double prosjek;
} Student;

void filtriraj(Student st[], size_t s, void (*akcija)(Student&), bool (*filter)(Student&)){
    for (size_t i=0; i<s; i++){
        if(filter(st[i])){
            akcija(st[i]);
        }
    }
}

void ispis(Student& st){
    cout << "Ime: "<<st.ime<<endl;
    cout << "JMBAG: "<<st.jmbag<<endl;
    cout << "Godina: "<<st.studyY<<endl;
    cout << "ECTS: "<<st.ECTS<<endl;
    cout << "Prosjek ocjena: "<<st.prosjek<<endl;
}

void godinaUp(Student& st){
    st.studyY++;
}


int main(){
    Student studenti[3]={
        {"Ivo Ivic","11111111",1,0,0.0},
        {"Mate Matic","22222222",2,50,3.9},
        {"Ante Antic","33333333",3,70,2.8}
    };

    auto jedanIs = [](Student& s){
        return s.studyY == 1 && s.ECTS > 0;
    };
    filtriraj(studenti, 3, ispis, jedanIs);

    auto prosjek = [](Student& s){
        return s.prosjek > 3.5;
    };
    filtriraj(studenti, 3, ispis, prosjek);

    auto ects45 = [](Student& s){
        return s.ECTS > 45;
    };
    filtriraj(studenti, 3, godinaUp, ects45);



    return 0;
}
