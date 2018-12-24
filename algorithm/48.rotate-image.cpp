/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (45.28%)
 * Total Accepted:    207.3K
 * Total Submissions: 456.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * Example 1:
 * 
 * 
 * Given input matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), count = 0;
        int up = 0, down = n - 1, left = 0, right = n - 1;
        vector<int> temp;
        while(left < right){
            temp.clear();
            temp = matrix[up];
            for(int i = count; i < n - count; i++){
                matrix[up][i] = matrix[n - i - 1][left];
            }

            for(int i = count; i < n - count; i++){
                matrix[i][left] = matrix[down][i];
            }

            for(int i = count; i < n - count; i++){
                matrix[down][i] = matrix[n - i - 1][right];
            }

            for(int i = count; i < n - count; i++){
                matrix[i][right] = temp[i];
            }

            up++, left++, down--, right--;
            count++;
        }
    }
};
