/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.94%)
 * Total Accepted:    206.6K
 * Total Submissions: 739.4K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<int> pr(n, 1);
        int count = 0;
        for(int i = 2; i < n; i++){
            if(pr[i] == 1){
                count++;
                for(int j = 2; i * j < n; j++){
                    pr[i * j] = 0;
                }
            }
        }

        return count;
    }
};
