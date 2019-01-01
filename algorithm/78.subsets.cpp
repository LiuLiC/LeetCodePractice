/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (49.58%)
 * Total Accepted:    307.7K
 * Total Submissions: 620.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& v, vector<vector<int>>& result){
        result.push_back(v);
        for(int i = start; i < nums.size(); i++){
            v.push_back(nums[i]);
            backtrack(nums, i + 1, v, result);
            v.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> v;
        backtrack(nums, 0, v, result);

        return result;
    }
};
