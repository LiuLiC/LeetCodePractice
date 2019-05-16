/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */
class Solution {
public:
    int getSum(int a, int b) {
        a = *(unsigned int*)&a;
        b = *(unsigned int*)&b;
        return b==0?a:getSum(a^b,(unsigned int)(a&b)<<1);
    }
};

