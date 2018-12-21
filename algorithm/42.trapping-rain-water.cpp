/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (40.44%)
 * Total Accepted:    228.9K
 * Total Submissions: 565K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int* dp_left_max = new int[len];
        int* dp_right_max = new int[len];
        dp_left_max[0] = 0;
        dp_right_max[len - 1] = 0;

        for(int i = 1; i < len; i++){
            dp_left_max[i] = max(dp_left_max[i - 1], height[i - 1]);
        }

        for(int i = len - 2; i >= 0; i--){
            dp_right_max[i] =  max(dp_right_max[i + 1], height[i + 1]);
        }

        int sum = 0;
        for(int i = 0; i < len; i++){
            int bound = min(dp_left_max[i], dp_right_max[i]);
            if(bound > height[i])
                sum += bound - height[i];
        }

        return sum;
    }
};
