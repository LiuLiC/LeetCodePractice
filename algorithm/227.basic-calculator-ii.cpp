/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (32.37%)
 * Total Accepted:    94.9K
 * Total Submissions: 292.3K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 */
class Solution {
public:
    int calculate(string s) {
        stringstream ss("+" + s);
        char op;
        int n = 0, result = 0, last = 0;

        while(ss >> op >> n){
            if(op == '+' || op == '-'){
                n = (op == '+' ? n : -n);
                result += n;
            }
            else{
                n = (op == '*' ? last * n : last / n);
                result = result - last + n;
            }
            last = n;
        }

        return result;
    }
};
