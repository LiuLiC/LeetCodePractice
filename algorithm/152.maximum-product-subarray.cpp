/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (28.24%)
 * Total Accepted:    182.1K
 * Total Submissions: 644.5K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int imax = result, imin = result;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                int temp = imax;
                imax = imin;
                imin = temp;
            }

            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            result = max(imax, result);
        }

        return result;
    }
};
