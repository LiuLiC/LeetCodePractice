/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (40.68%)
 * Total Accepted:    161.2K
 * Total Submissions: 396.4K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp({0});
        if(n <= 0)
            return dp[0];
        
        for(int i = 1; i <= n; i++){
            int num = INT_MAX, j = 1;
            while(j * j <= i){
                num = min(num, dp[i - j * j] + 1);
                j++;
            }
            
            dp.push_back(num);
        }
        
        return dp[dp.size() - 1];
    }
};

