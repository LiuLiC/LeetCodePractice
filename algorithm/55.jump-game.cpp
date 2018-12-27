/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (30.62%)
 * Total Accepted:    216.6K
 * Total Submissions: 705.8K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
            return true;
        
        for(int i = 0; i < nums.size(); i++){
            nums[i] += i;
        }

        int cur = 0, next = 0;
        while(true){
            if(nums[cur] < nums.size() - 1){
                int max = 0;
                for(int i = cur + 1; i <= nums[cur]; i++){
                    if(max <= nums[i]){
                        max = nums[i];
                        next = i;
                    }
                }
            }
            else
                return true;

            if(cur == next)
                return false;
            
            cur = next;
        }
    }
};
