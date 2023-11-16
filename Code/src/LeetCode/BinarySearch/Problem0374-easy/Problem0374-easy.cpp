//
// Created by 阳寜 on 2023/11/16.
//
#include<bits/stdc++.h>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = n;
        long long ans = (left + right)/2;
        while (guess(ans) != 0) {
            if (guess(ans) == -1) {
                right = ans - 1;
                ans = (left + right)/2;
            }else {
                left = ans + 1;
                ans = (left + right)/2;
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}
