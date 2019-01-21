/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (26.31%)
 * Total Accepted:    142.7K
 * Total Submissions: 541.7K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
class Solution {
public:
    vector<string> findNext(string s, unordered_map<string, int>& wordMap, unordered_map<string, vector<string>>& mem){
        if(mem.find(s) != mem.end())
            return mem[s];

        vector<string> result;
        if(s.size() == 0){
            result.push_back("");
            return result;
        }

        for(auto it = wordMap.begin(); it != wordMap.end(); it++){
            string target = it->first;
            if(s.substr(0, target.size()) == target){
                vector<string> sublist = findNext(s.substr(target.size()), wordMap, mem);
                for(int i = 0; i < sublist.size(); i++){
                    result.push_back(target + (sublist[i] == "" ? "" : " ") + sublist[i]);
                }
            }
        }

        mem[s] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> wordMap;
        for(int i = 0; i < wordDict.size(); i++){
            wordMap[wordDict[i]] = i;
        }

        unordered_map<string, vector<string>> mem;

        return findNext(s, wordMap, mem);
    }
};
