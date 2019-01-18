/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (38.94%)
 * Total Accepted:    146.9K
 * Total Submissions: 377.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--])
                return false;
        }

        return true;
    }

    void dfs(string& s, vector<string>& path, int start, vector<vector<string>>& result){
        if(start == s.size()){
            result.push_back(path);
            return;
        }

        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start, i)){
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, path, i + 1, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.empty())
            return result;

        vector<string> path;
        dfs(s, path, 0, result);

        return result;
    }
};
