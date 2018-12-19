/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (38.58%)
 * Total Accepted:    240.1K
 * Total Submissions: 621.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:
    string next(string str){
        string result = "";
        char prev = str[0];
        int count = 0; 

        if(str.length() == 1)
            return "1" + str;

        for(int i = 0; i < str.length(); i++){
            if(str[i] == prev){
                count++;
            }
            else{
                result += to_string(count);
                result += prev;
                count = 1;
                prev = str[i];
            }
        }
        result += to_string(count);
        result += prev;

        return result;
    }

    string countAndSay(int n) {
        string str = "1";
        if(n == 1)
            return str;
        
        for(int i = 2; i <= n; i++){
            str = next(str);
        }

        return str;
    }
};
