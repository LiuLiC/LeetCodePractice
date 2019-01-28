/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (25.01%)
 * Total Accepted:    117.3K
 * Total Submissions: 468.9K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */
class Solution {
public:
    static bool largerThan(const string& a, const string& b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        string result;
        if(nums.size() == 0)
            return result;

        vector<string> nums_string;
        for(int i = 0; i < nums.size(); i++){
            nums_string.push_back(to_string(nums[i]));
        }

        sort(nums_string.begin(), nums_string.end(), largerThan);

        for(int i = 0; i < nums_string.size(); i++){
            result += nums_string[i];
        }

        if(result[0] == '0')
            return "0";

        return result;
    }
};
