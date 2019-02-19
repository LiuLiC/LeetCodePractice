/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (53.60%)
 * Total Accepted:    220.6K
 * Total Submissions: 411.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty())
            return vector<int>();

        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);

        left[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            left[i] = left[i - 1] * nums[i - 1];
        }

        right[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> result(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            result[i] = left[i] * right[i];
        }

        return result;
    }
};
