/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.27%)
 * Total Accepted:    357K
 * Total Submissions: 1.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    bool checkValid(vector<string>& strs, int pos){
        if(strs.empty())
            return false;
        for(int i = 0; i < strs.size(); i++){
            if(pos >= strs[i].length())
                return false;
        }

        return true;
    }

    bool checkSame(vector<string>& strs, int pos, string& result){
        if(!checkValid(strs, pos))
            return false;
        
        char cur = strs[0][pos];
        for(int i = 1; i < strs.size(); i++){
            if(cur != strs[i][pos])
                return false;
        }

        result += cur;
        return true;
    }

    
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int pos = 0;

        while(checkSame(strs, pos, result)){
            pos++;
        }

        return result;
    }
};
