/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        int max3PowerInt = 1162261467;
        if(n <= 0 || n > max3PowerInt)
            return false;
        else
            return max3PowerInt % n == 0;
    }
};

