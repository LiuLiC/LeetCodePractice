/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.42%)
 * Total Accepted:    422K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right], target = -nums[i];
                if(sum == target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    left++;
                    right--;

                    while(nums[left] == nums[left - 1])
                        left++;
                    while(nums[right] == nums[right + 1])
                        right--;
                }
                else if(sum < target)
                    left++;
                else 
                    right--;
            }
        }
        
        return result;
    }
};
