/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (29.16%)
 * Total Accepted:    196.5K
 * Total Submissions: 673.4K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty())
            return "";

        // initialize hashmap for t
        int count = t.length();
        int hash[128] = {0};
        bool require[128] = {false};
        for(int i = 0; i < count; i++){
            char c = t[i];
            hash[c]++;
            require[c] = true;
        }

        int i = -1, j = 0, min_len = INT_MAX, min_idx = 0;

        while(i < (int)s.length() && j < s.length()){
            if(count){
                i++;
                hash[s[i]]--;
                if(require[s[i]] && hash[s[i]] >= 0){
                    count--;
                }
            }
            else{
                if(min_len > i - j + 1){
                    min_len = i - j + 1;
                    min_idx = j;
                }
                hash[s[j]]++;
                if(require[s[j]] && hash[s[j]] > 0){
                    count++;
                }
                j++;
            }
        }

        if(min_len == INT_MAX)
            return "";

        return s.substr(min_idx, min_len);
    }
};
