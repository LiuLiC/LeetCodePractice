/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.71%)
 * Total Accepted:    409.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), index1 = 0, index2 = 0, max_len = 0;
        
        if(len == 0)
            return "";

        bool **dp = new bool*[len];
        for(int k = 0; k < len; k++){
            dp[k] = new bool[len];
            dp[k][k] = true;
        } 

        for(int j = 0; j < len; j++){
            for(int i = 0; i < j; i++){
                dp[i][j] = (s[i] == s[j]) && ((j - i < 2) || dp[i + 1][j - 1]);
                if(dp[i][j]){
                    if(j - i + 1 > max_len){
                        max_len = j - i + 1;
                        index1 = i;
                        index2 = j;
                    }
                }
            }
        }

        return s.substr(index1, index2 - index1 + 1);
    }
};
