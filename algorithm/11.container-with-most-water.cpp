/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (40.16%)
 * Total Accepted:    271.5K
 * Total Submissions: 674.4K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */
class Solution {
public:
    // Time - O(n)
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxArea = 0;
        while(i < j){
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, area);

            if(height[i] >= height[j])
                j--;
            else
                i++;
        }

        return maxArea;
    }

    // Time - O(n^2)
    // int maxArea(vector<int>& height) {
    //     int maxArea = 0;
    //     for(int i = 0; i < height.size(); i++){
    //         for(int j = i; j < height.size(); j++){
    //             int min_height = min(height[i], height[j]);
    //             int area = min_height * (j - i);
    //             maxArea = max(maxArea, area);
    //         }
    //     }

    //     return maxArea;
    // }
};
