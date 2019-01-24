/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (50.99%)
 * Total Accepted:    335.5K
 * Total Submissions: 657.9K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    // Hash Table - Time O(n), Space O(n) 
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> um;
    //     for(int i = 0; i < nums.size(); i++){
    //         um[nums[i]]++;
    //         auto search = um.find(nums[i]);
    //         if(search->second > nums.size() / 2)
    //             return search->first;
    //     }

    //     return 0;
    // }

    // Time O(n), Space O(1)
    int majorityElement(vector<int>& nums) {
        int result = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                result = nums[i];
            }

            count += (result == nums[i] ? 1 : -1);
        }

        return result;
    }
};
