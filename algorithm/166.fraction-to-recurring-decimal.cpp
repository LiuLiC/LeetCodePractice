/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (19.00%)
 * Total Accepted:    80.5K
 * Total Submissions: 423.5K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        string result = "";
        if(numerator < 0 ^ denominator < 0)
            result += "-";
        
        long long num = (numerator < 0) ? (long long)numerator * -1 : numerator;
        long long de = (denominator < 0) ? (long long)denominator * -1 : denominator;

        result += to_string(num / de);

        if(num % de == 0)
            return result;

        result += ".";

        unordered_map<int, int> m;
        for(long long r = num % de; r != 0; r = r % de){
            if(m.find(r) != m.end()){
                result.insert(m[r], 1, '(');
                result += ')';
                break;
            }

            m[r] = result.size();

            r *= 10;
            result += to_string(r / de);
        }

        return result;
    }
};
