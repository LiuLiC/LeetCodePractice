/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (33.83%)
 * Total Accepted:    287.5K
 * Total Submissions: 849.7K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool findNext(string s, int index, unordered_map<string, int>& wordMap, unordered_map<int, int>& unreachable){
        if(index == s.size())
            return true;

        if(unreachable.find(index) != unreachable.end())
            return false;

        for(int i = 1; i < s.size() - index + 1; i++){
            string target = s.substr(index, i);
            
            if(wordMap.find(target) != wordMap.end()){
                if(findNext(s, index + i, wordMap, unreachable))
                    return true;
                else
                    unreachable[index + i] = 1; 
            }       
        }

        unreachable[index] = 1;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> wordMap;
        for(int i = 0; i < wordDict.size(); i++){
            wordMap[wordDict[i]] = i;
        }

        unordered_map<int, int> unreachable;
        return findNext(s, 0, wordMap, unreachable);
    }
};
