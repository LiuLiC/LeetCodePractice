/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (28.85%)
 * Total Accepted:    191.7K
 * Total Submissions: 662.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    // More understandable way
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        if(rows == 0)
            return result;
        int cols = matrix[0].size();
        if(cols == 0)
            return result;

        int rowStart = 0, rowEnd = rows - 1, colStart = 0, colEnd = cols - 1;
        while(rowStart <= rowEnd && colStart <= colEnd){
            for(int i = colStart; i <= colEnd; i++)
                result.push_back(matrix[rowStart][i]);
            rowStart++;

            for(int i = rowStart; i <= rowEnd; i++)
                result.push_back(matrix[i][colEnd]);
            colEnd--;

            if(rowStart <= rowEnd){
                for(int i = colEnd; i >= colStart; i--)
                    result.push_back(matrix[rowEnd][i]);
                rowEnd--;
            }

            if(colStart <= colEnd){
                for(int i = rowEnd; i >= rowStart; i--)
                    result.push_back(matrix[i][colStart]);
                colStart++;
            }
        }

        return result;
    }
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     vector<int> result;
    //     if(matrix.empty())
    //         return result;

    //     int m = matrix.size(), n = matrix[0].size(), visited = 0, i = 0, j = 0;
    //     if(m == 1 || n == 1){
    //         if(m == 1){
    //             while(j < n)
    //                 result.push_back(matrix[0][j++]);
    //         }else if(n == 1){
    //             while(i < m)
    //                 result.push_back(matrix[i++][0]);
    //         }
            
    //         return result;
    //     }
    //     int up = 0, right = n, down = m, left = 0;

    //     while(visited < m * n){

    //         while(j < right - 1){
    //             result.push_back(matrix[i][j]);
    //             j++;
    //             visited++;
    //         }
    //         right--;
    //         while(i < down - 1){
    //             result.push_back(matrix[i][j]);
    //             i++;
    //             visited++;
    //         }
    //         down--;
    //         while(j > left){
    //             result.push_back(matrix[i][j]);
    //             j--;
    //             visited++;
    //         }
    //         left++;
    //         while(i > up){
    //             result.push_back(matrix[i][j]);
    //             i--;
    //             visited++;
    //         }
    //         up++;
    //         i++, j++;

    //         if(left == right - 1 || up == down - 1){
    //             if(left == right - 1){
    //                 while(i < down)
    //                     result.push_back(matrix[i++][j]);
    //                 break;
    //             }
    //             else if(left != right - 1){
    //                 while(j < right)
    //                     result.push_back(matrix[i][j++]);
    //                 break;
    //             }
    //         }
    //     }

    //     return result;
    // }
};
