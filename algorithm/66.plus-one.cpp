/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.30%)
 * Total Accepted:    325.7K
 * Total Submissions: 808.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size() - 1] != 9){
            digits[digits.size() - 1]++;
        }
        else{

            int i = digits.size() - 1;

            for(; i > 0; i--){
                digits[i] = 0;
                if(digits[i - 1] != 9)
                    break;
            }

            if(i > 0)
                digits[i - 1]++;
            else
                digits[0]++;
                
            if(digits[0] == 10){
                digits.push_back(0);
                digits[0] = 1;
            }
        }

        return digits;
    }
};
