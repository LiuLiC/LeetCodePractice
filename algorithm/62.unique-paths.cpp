/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (45.43%)
 * Total Accepted:    241.5K
 * Total Submissions: 531.6K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */
class Solution {
public:
    // Recursive method : Time Limit Exceeded
    /* void move(int& i, int& j, int m, int n, int& count){
        if(i == m - 1 && j == n - 1){
            count++;
            return;
        }

        if(i < m){
            move(++i, j, m, n, count);
            i--;
        }

        if(j < n){
            move(i, ++j, m, n, count);
            j--;
        }
    }

    int uniquePaths(int m, int n) {
        int result = 0, i = 0, j = 0;
        move(i, j, m, n, result);

        return result;
    } */
};
