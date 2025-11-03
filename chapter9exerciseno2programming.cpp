#include <iostream>
#include <iomanip>
using namespace std;

struct studentdata{
    string studentfirstname;
    string studentlastname;
    int score;
    char grade;
};

void Instudentdata(studentdata student[], int size){
    cout << "data dari ke-" << size << "mahasiswa adalah: " << endl;
    for (int i = 0; i < size; i++){
        cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama depan= ";
        cin >> student[i].studentfirstname;
        cout << "Nama belakang= ";
        cin >> student[i].studentlastname;
        cout << "masukkan nilai anda(1-100)= ";
        cin >> student[i].score;
        cout << endl;
    }
}

void Gradingsystem(studentdata student[], int size){
    for (int i = 0; i < size; i++){
        if (student[i].score >= 90){
            student[i].grade = 'A';
        }
        else if (student[i].score >= 80){
            student[i].grade = 'B';
        }
        else if (student[i].score >= 70){
            student[i].grade = 'C';
        }
        else if (student[i].score >= 60){
            student[i].grade = 'D';
        }
        else {
            student[i].grade = 'E';
        }
    }
}

int Findhighscore(studentdata student[], int size){
    int highestscore = student[0].score;

    for (int i=0; i<size;i++){
        if (student[i].score > highestscore){
            highestscore = student[i].score;
        }
    }
    return highestscore;
    }
    

void Specialaward(studentdata student[], int size, int highestscore){
    cout << "Mahasiswa dengan nilai tertinggi adalah ";
    cout << "Nilainya adalah "<< highestscore << endl;

    for(int i=0; i<size; i++){
        if(student[i].score == highestscore){
            cout << student[i].studentfirstname << " " << student[i].studentlastname << endl;
        }
    }
}

void Printstudentdata(studentdata student[], int size){
    cout << "Nama para mahasiswa dan nilai mereka" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << left << setw(5) << "No" << setw(30) << "Nama Mahasiswa" << setw(15)
    << "Test Score" << setw(10) << "Grade" << endl;
    cout << "------------------------------------------------------" << endl;

    for (int i= 0; i < size; i++){
        string Fullname = student[i].studentlastname + ", " + student[i].studentfirstname;
        cout << left << setw(5) << i + 1
             << setw(30) << Fullname
             << setw(15) << student[i].score
             << setw(10) << student[i].grade << endl;
    }
    cout << "------------------------------------------------------" << endl;
}

int main(){
    int size=20;
    studentdata student[size];

    Instudentdata(student, size);
    Gradingsystem(student, size);
    Printstudentdata(student, size);
    
    int highestScore = Findhighscore(student, size);
    Specialaward(student, size, highestScore);
    
    return 0;
}
