//
// Created by 阳寜 on 2023/3/6.
//
#include<bits/stdc++.h>

using namespace std;

struct Student {
    char id[15];
    int score;
    int locationNumber; //考场号
    int localRank;  //考场内排名
}stu[30010];
bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    else return strcmp(a.id,b.id) < 0;
}
int main() {
    int n,k,num = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> stu[num].id >> stu[num].score;
            stu[num].locationNumber = i;
            num++;
        }
        sort(stu + num - k, stu + num, cmp);    //先从考场内排名
        stu[num - k].localRank = 1;
        for (int j = num - k + 1 ; j < num; ++j) {
            if (stu[j].score == stu[j-1].score) {
                stu[j].localRank = stu[j-1].localRank;
            }else {
                stu[j].localRank = j + 1 - (num - k);
            }
        }
    }
    cout << num << endl;
    sort(stu,stu+num,cmp);  //所有考场一起排名
    int r = 1;
    for (int i = 0; i < num; ++i) {
        if (i > 0 && stu[i].score != stu[i - 1].score) {
            r = i + 1;
        }
        cout << stu[i].id << " ";
        cout << r <<" "<< stu[i].locationNumber << " " << stu[i].localRank << endl;
    }
    return 0;
}
