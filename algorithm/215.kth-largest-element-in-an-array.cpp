/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (45.29%)
 * Total Accepted:    312.4K
 * Total Submissions: 688K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[lo];

        while(lo < hi){
            while(lo < hi && pivot >= nums[hi])
                hi--;
            nums[lo] = nums[hi];
            while(lo < hi && pivot <= nums[lo])
                lo++;
            nums[hi] = nums[lo];
        }

        nums[lo] = pivot;
        return lo;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        while(true){
            int par = partition(nums, lo, hi);

            if(par + 1 == k)
                return nums[par];
            else if(par + 1 > k)
                hi = par - 1;
            else if(par + 1 < k)
                lo = par + 1;
        }

        return 0;
    }
};
