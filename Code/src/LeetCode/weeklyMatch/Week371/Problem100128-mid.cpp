//
// Created by 阳寜 on 2023/11/12.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        set<string> ans1;
        for (int i = 0; i < access_times.size(); ++i) {
            int num = 0;
            string stri1 = access_times[i][0];
            string stri2 = access_times[i][1];
            for (int j = 0; j < access_times.size(); ++j) {
                if (access_times[j][0] == stri1 && oneHour(stri2,access_times[j][1])) {
                    num++;
                }
            }
            if (num >= 3) {
                ans1.insert(stri1);
            }
        }
        for(auto i : ans1) {
            ans.push_back(i);
        }
        return ans;
    }
    bool oneHour(string str1,string str2) {
        if (str1[0] == str2[0] && str1[1] == str2[1] && stoi(str2.substr(2,2)) >= stoi(str1.substr(2,2))) return true;
        if (stoi(str2.substr(0,2)) - stoi(str1.substr(0,2)) ==1) {
            if (stoi(str2.substr(2,2)) < stoi(str1.substr(2,2))) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    Solution solution;
    vector<vector<string>> access_times = {{"edypxglivg","1604"},
                                           {"edypxglivg","1502"},
                                           {"edypxglivg","1507"}};
    cout << solution.findHighAccessEmployees(access_times)[0];
    return 0;
}
