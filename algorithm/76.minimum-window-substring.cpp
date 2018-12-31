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
    bool isValid(unordered_map<char, int>& p){
        for(auto it = p.begin(); it != p.end(); it++){
            if(it->second > 0)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        // initialize hashmap for t
        unordered_map<char, int> p;
        for(int i = 0; i < t.length(); i++){
            char c = t[i];
            if(p.count(c) == 0){
                p[c] = 1;
            }
            else{
                p[c]++;
            }
        }

        int i = 0, j = 0, len = INT_MAX;
        string result = "";
        while(j < s.length() + 1){
            // cout << i << '\t' << j << endl;
            while(i <= j && j < s.length()){
                char cur_j = s[j];
                if(p.count(cur_j) == 0){
                    j++;
                }
                else{
                    p.find(cur_j)->second--;
                    if(isValid(p)){
                        string valid_str = s.substr(i, j - i + 1);
                        if(valid_str.length() < len){
                            len = valid_str.length();
                            result = valid_str;
                        }
                        break;
                    }
                    j++;
                }
            }

            // cout << i << '\t' << j << endl;

            while(i <= j){
                char cur_i = s[i];
                if(p.count(cur_i) == 0){
                    i++;
                    string valid_str = s.substr(i, j - i + 1);
                    if(valid_str.length() < len){
                        len = valid_str.length();
                        result = valid_str;
                    }
                }
                else{
                    p.find(cur_i)->second++;
                    i++;
                    break;
                }
            }
            j++;

            // cout << i << '\t' << j << endl;

        }

        return result;
    }
};
