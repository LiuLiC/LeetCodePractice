/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (51.45%)
 * Total Accepted:    270.1K
 * Total Submissions: 525K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    void backtrack(vector<string> &result, string cur, int open, int close, const int max){
        if(cur.length() == 2 * max){
            result.push_back(cur);
            return;
        }

        if(open < max){
            backtrack(result, cur + '(', open + 1, close, max);
        }
        if(close < open){
            backtrack(result, cur + ')', open, close + 1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
