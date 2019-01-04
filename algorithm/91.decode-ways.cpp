/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.47%)
 * Total Accepted:    223.3K
 * Total Submissions: 1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for(int i = 2; i <= s.length(); i++){
            int one_prev = stoi(s.substr(i - 1, 1));
            int two_prev = stoi(s.substr(i - 2, 2));

            if(one_prev >= 1 && one_prev <= 9)
                dp[i] += dp[i - 1];
            if(two_prev >= 10 && two_prev <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[s.length()];
    }
};
