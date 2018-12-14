/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.30%)
 * Total Accepted:    335.5K
 * Total Submissions: 1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int middle = (low + high) / 2;
            if(nums[middle] == target)
                return middle;
            
            if(nums[low] > nums[high]){
                if(nums[middle] > target && nums[middle] >= nums[low]){
                    if(nums[low] > target){
                        low = middle + 1;
                    }
                    else{
                        high = middle - 1;
                    }
                }
                else if(nums[middle] < target && nums[middle] >= nums[low]){
                    low = middle + 1;
                }
                else if(nums[middle] > target && nums[middle] <= nums[high]){
                    high = middle - 1;
                }
                else if(nums[middle] < target && nums[middle] <= nums[high]){
                    if(nums[high] < target){
                        high = middle - 1;
                    }
                    else{
                        low = middle + 1;
                    }
                }
            }
            else{
                if(nums[middle] > target)
                    high = middle - 1;
                else
                    low = middle + 1;
            }
        }

        return -1;
    }
};
