/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.24%)
 * Total Accepted:    631.6K
 * Total Submissions: 2.5M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, str_len = s.length();
        int i = 0, j = 0;
        unordered_map<char, int> record;

        while(i < str_len && j < str_len){
            auto search = record.find(s[j]);
            if(search == record.end()){
                record[s[j]] = j;
                j++;
                maxLen = max(maxLen, j - i);
            }
            else{
                record.erase(record.find(s[i]));
                i++;
            }
        }

        return maxLen;
    }

    // *** 
    // First Submission, time consumption - O(n^2)
    // ***
     
    // int lengthOfLongestSubstring(string s) {
    //     int maxLen = 0;
    //     unordered_map<char, int> record;

    //     for(int i = 0; i < s.length(); i++){
    //         int len = 1;
    //         record[s[i]] = i;
    //         for(int j = i + 1; j < s.length(); j++){
    //             if(record.find(s[j]) != record.end()){
    //                 i = record.find(s[j])->second;
    //                 record.clear();
    //                 break;
    //             }
    //             else{
    //                 record[s[j]] = j;
    //                 len++;
    //             }
    //         }

    //         if(len > maxLen)
    //             maxLen = len;
    //     }

    //     return maxLen;
    // }
};
