/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (50.39%)
 * Total Accepted:    294.4K
 * Total Submissions: 583.5K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++){
            if(um.find(nums[i]) != um.end())
                return true;
            else
                um[nums[i]] = i;
        }

        return false;
    }
};
