/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (51.70%)
 * Total Accepted:    311.5K
 * Total Submissions: 600.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    void permute_recur(vector<vector<int>>& result, vector<int>& v, vector<int>& nums, vector<bool>& used){
        if(v.size() == nums.size()){
            result.push_back(v);
            return;
        }

        for(int i = 0; i < used.size(); i++){
            if(!used[i]){
                v.push_back(nums[i]);
                used[i] = true;
                permute_recur(result, v, nums, used);
                used[i] = false;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> v;

        permute_recur(result, v, nums, used);
        return result;
    }
};
