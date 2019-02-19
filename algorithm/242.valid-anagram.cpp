/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (50.73%)
 * Total Accepted:    297.3K
 * Total Submissions: 586.1K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        int hash[26];
        for(int i = 0; i < 26; i++)
            hash[i] = 0;

        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(hash[i] != 0)
                return false;
        }

        return true;
    }
};
