/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.80%)
 * Total Accepted:    165K
 * Total Submissions: 1M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 231 − 1 when the division
 * result overflows.
 * 
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long long long_dividend = labs(dividend);
        long long long_divisor = labs(divisor);
        int result = 0;
        while(long_dividend >= long_divisor){
            long long temp = long_divisor, mul = 1;
            while(long_dividend >= (temp << 1)){
                temp <<= 1;
                mul <<= 1;
            }

            result += mul;
            long_dividend -= temp;
        }

        return sign * result;
    }
};
