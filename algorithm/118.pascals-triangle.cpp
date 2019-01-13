/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (43.67%)
 * Total Accepted:    215.8K
 * Total Submissions: 494.2K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if(numRows == 0)
            return result;
        
        vector<int> one(1, 1);
        result.push_back(one);
        if(numRows == 1)
            return result;

        vector<int> two(2, 1);
        result.push_back(two);
        if(numRows == 2)
            return result;

        for(int i = 2; i < numRows; i++){
            vector<int> level;
            level.push_back(1);
            for(int j = 1; j < i; j++){
                level.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            level.push_back(1);
            result.push_back(level);
        }

        return result;
    }
};
