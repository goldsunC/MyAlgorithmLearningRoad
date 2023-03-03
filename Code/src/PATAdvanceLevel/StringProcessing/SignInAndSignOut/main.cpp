//
// Created by 阳寜 on 2023/3/3.
//
#include "iostream"
using namespace std;
int main() {
    int num;
    string open_id,open_time;
    string close_id,close_time;
    cin >> num ;
    for (int i = 0; i < num; i++) {
        string id, in_time,out_time;
        cin >> id >> in_time >> out_time;
        if (!i || in_time < open_time) {
            open_id = id;
            open_time = in_time;
        }
        if (!i || out_time > close_time) {
            close_id = id;
            close_time = out_time;
        }
    }
    cout << open_id << " " << close_id <<endl;
    return 0;
}