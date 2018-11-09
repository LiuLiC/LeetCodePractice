/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (39.11%)
 * Total Accepted:    1.2M
 * Total Submissions: 3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            table[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int left = target - nums[i];
            if(table.find(left) != table.end() && table[left] != i){
                result.push_back(i);
                result.push_back(table[left]);
                return result;
            }
        }
    }
};
