/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0)
            return -1;
        
        vector<int> ha(26, 0);
        for(int i = 0; i < s.size(); i++){
            ha[s[i] - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            if(ha[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

