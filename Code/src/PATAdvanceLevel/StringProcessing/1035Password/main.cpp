//
// Created by 阳寜 on 2023/3/4.
//
// Todo:PAT评分17分，有一个测试点没过，问题待排查。

#include "iostream"
#include "vector"
using namespace std;
int main() {
    int N;
    cin >> N;
    int NN = N;
    string users[N],password[N];
    int symbol = 0;
    vector<int> M;
    for (int i = 0; i < N; ++i) {
        cin >> users[i] >> password[i];
    }
    for (int i = 0; i < NN; ++i) {
        for (int j = 0; j < password[i].size(); ++j) {
            if (password[i][j] == '1') {
                password[i][j] = '@';
                symbol = 1;
            }
            else if (password[i][j] == '0') {
                password[i][j] = '%';
                symbol = 1;
            }
            else if (password[i][j] == 'l') {
                password[i][j] = 'L';
                symbol = 1;
            }
            else if (password[i][j] == 'O') {
                password[i][j] = 'o';
                symbol = 1;
            }
        }
        if (symbol) {
            N--;
            M.emplace_back(i);
            symbol = 0;
        }
    }
    if (NN == N) {
        cout << "There is "<< to_string(N) << " account and no account is modified";
    }else{
        cout << NN - N << endl;
        for (int i = 0; i < NN - N; ++i) {
            cout << users[M[i]] << " " << password[M[i]] << endl;
        }
    }
    return 0;
}