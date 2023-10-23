//
// Created by 阳寜 on 2023/10/23.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string &str : details) {
            if (stoi(str.substr(11,2)) > 60) {
                count++;
            }
        }
        return count;
    }
};

int main() {


    return 0;
}
