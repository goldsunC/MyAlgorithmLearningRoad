//
// Created by 阳寜 on 2023/3/4.
//
#include "iostream"
using namespace std;
int main() {
    int N;
    cin >> N;
    string boyName,boyID;
    string girlName,girlID;
    int boyGrade = 101,girlGrade = -1;

    string name,ID;
    char gender;
    int grade;
    for (int i = 0; i < N; ++i) {
        cin >> name >> gender >> ID >> grade;
        if (gender == 'M') {
            if (grade < boyGrade) {
                boyName = name;
                boyID = ID;
                boyGrade = grade;
            }
        }
        if (gender == 'F') {
            if (grade > girlGrade) {
                girlName = name;
                girlID = ID;
                girlGrade = grade;
            }
        }
    }
    if (girlName.empty() || boyName.empty()) {
        if (girlName.empty()) {
            cout << "Absent" << endl;
        }else{
            cout << girlName << " " << girlID << endl;
        }
        if (boyName.empty()) {
            cout << "Absent" << endl;
        }else{
            cout << boyName << " " << boyID << endl;
        }
        cout << "NA" << endl;
    }else {
        cout << girlName << " " << girlID << endl;
        cout << boyName << " " << boyID << endl;
        if (girlGrade >= boyGrade) {
            cout << girlGrade - boyGrade;
        }else{
            cout << boyGrade - girlGrade;
        }
    }
    return 0;
}