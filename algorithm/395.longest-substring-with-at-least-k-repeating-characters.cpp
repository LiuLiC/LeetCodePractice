/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0)
            return 0;

        int count[26] = {0};
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
        }

        bool ok = true;
        for(int i = 0; i < 26; i++){
            if(count[i] != 0 && count[i] < k)
                ok = false;
        }

        if(ok)
            return s.size();

        int begin = 0, end = 0, result = 0;
        while(end < s.size()){
            if(count[s[end] - 'a'] < k){
                result = max(result, longestSubstring(s.substr(begin, end - begin), k));
                begin = end + 1;
            }
            end++;
        }

        result = max(result, longestSubstring(s.substr(begin), k));

        return result;
    }
};

