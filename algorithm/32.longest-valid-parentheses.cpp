/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.05%)
 * Likes:    1775
 * Dislikes: 85
 * Total Accepted:    186.9K
 * Total Submissions: 736.5K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;

        vector<int> dp(s.size(), 0);
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(i > 0 && s[i-1] == '('){
                    dp[i] = (i >= 2 ? dp[i-2] + 2 : 2);
                }
                else if(i > 0 && s[i-1] == ')'){
                    if(i - dp[i-1] - 1 >= 0 && s[i-dp[i-1]-1] == '('){
                        dp[i] = dp[i-1] + (i - dp[i-1] - 2 >= 0 ? dp[i - dp[i-1] - 2] + 2 : 2);
                    }
                }
            }

            result = max(result, dp[i]);
        }
        
        return result;
    }
};

