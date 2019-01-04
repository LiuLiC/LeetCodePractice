/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (29.63%)
 * Total Accepted:    149.6K
 * Total Submissions: 504.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int maxAreaWithMiddle(vector<int>& heights, int start, int middle, int end){
        int i = middle, j = middle + 1;
        int area = 0, height = min(heights[i], heights[j]);

        while(i >= start && j <= end){
            height = min(height, min(heights[i], heights[j]));
            area = max(area, (j - i + 1) * height);

            if(i == start){
                j++;
            }
            else if(j == end){
                i--;
            }
            else{
                if(heights[i - 1] > heights[j + 1])
                    i--;
                else
                    j++;
            }
        }

        return area;
    }

    int maxArea(vector<int>& heights, int start, int end){
        if(start == end)
            return heights[start];

        int middle = (start + end) / 2;

        int area = maxArea(heights, start, middle);
        area = max(area, maxArea(heights, middle + 1, end));
        area = max(area, maxAreaWithMiddle(heights, start, middle, end));

        return area;
    }

    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 0)
            return 0;

        return maxArea(heights, 0, len - 1);
    }
};
