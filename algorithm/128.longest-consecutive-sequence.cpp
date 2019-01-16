/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (40.39%)
 * Total Accepted:    182.4K
 * Total Submissions: 451.3K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]] = i;
        }

        int longest_len = 0;
        for(int i = 0; i < nums.size(); i++){
            if(um.find(nums[i] - 1) == um.end()){
                int cur = nums[i], len = 1;
                while(um.find(cur + 1) != um.end()){
                    cur++;
                    len++;
                }

                longest_len = max(len, longest_len);
            }
        }

        return longest_len;
    }
};
