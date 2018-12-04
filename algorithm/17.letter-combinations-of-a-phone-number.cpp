/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (39.09%)
 * Total Accepted:    309.5K
 * Total Submissions: 791.7K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
private:
    vector<string> to_letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> combine(string all_letter, vector<string> &strs){
        vector<string> res;

        for(int i = 0; i < all_letter.length(); i++){
            for(int j = 0; j < strs.size(); j++){
                res.push_back(strs[j] + all_letter[i]);
            }
        }

        return res;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if(digits.length() == 0 || digits == "")
            return result;

        result.push_back("");
        for(int i = 0; i < digits.length(); i++){
            result = combine(to_letter[digits[i] - '0'], result);
        }

        return result;
    }
};
