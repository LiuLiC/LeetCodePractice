/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int m = 0, n = s.size() - 1;
        while(m < n){
            char c = s[m];
            s[m] = s[n];
            s[n] = c;
            m++;
            n--;
        }
    }
};

