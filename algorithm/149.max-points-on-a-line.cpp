/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.45%)
 * Total Accepted:    109.8K
 * Total Submissions: 710.2K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int result = 0;

        for(int i = 0; i < points.size(); i++){
            int same = 0;
            int vertical = 0;
            int cur_max = 1;
            unordered_map<string, int> um;
            for(int j = i + 1; j < points.size(); j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    same++;
                else if(points[i].x == points[j].x)
                    vertical++;
                else{
                    int diff_x = points[i].x - points[j].x;
                    int diff_y = points[i].y - points[j].y;
                    int g = __gcd(diff_x, diff_y);
                    
                    diff_x /= g;
                    diff_y /= g;

                    if(diff_y < 0){
                        diff_y *= -1;
                        diff_x *= -1;
                    }

                    stringstream ss;
                    ss << diff_y << "," << diff_x;
                    um[ss.str()]++;
                    cur_max = max(cur_max, um[ss.str()] + 1);
                }

                cur_max = max(cur_max, vertical + 1);
            }

            result = max(result, same + cur_max);
        }

        return result;
    }
};
