/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (32.42%)
 * Total Accepted:    243.7K
 * Total Submissions: 751.7K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    int findLeft(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int middle = (low + high) / 2;
            if(nums[middle] == target){
                if(middle == 0 || (middle > 0 && nums[middle - 1] != target))
                    return middle;
                else{
                    high = middle - 1;
                }
                continue;
            }

            if(nums[middle] > target)
                high = middle - 1;
            else
                low = middle + 1;
        }

        return -1;
    }

    int findRight(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int middle = (low + high) / 2;
            if(nums[middle] == target){
                if(middle == nums.size() - 1 || (middle < nums.size() - 1 && nums[middle + 1] != target))
                    return middle;
                else{
                    low = middle + 1;
                }
                continue;
            }

            if(nums[middle] > target)
                high = middle - 1;
            else
                low = middle + 1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(findLeft(nums, target));
        result.push_back(findRight(nums, target));

        return result;
    }
};
