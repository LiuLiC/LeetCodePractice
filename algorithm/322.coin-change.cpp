/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
class Solution {
public:
    int helper(vector<int>& coins, int left, vector<int>& count){
        if(left < 0)
            return -1;
        if(left == 0)
            return 0;

        if(count[left - 1] != 0)
            return count[left - 1];

        int min = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int res = helper(coins, left - coins[i], count);
            if(res >= 0 && res < min){
                min = res + 1;
            }
        }
        count[left - 1] = (min == INT_MAX) ? -1 : min;
        return count[left - 1];
    }

    int coinChange2(vector<int>& coins, int amount) {
        if(amount < 1)
            return 0;

        vector<int> count(amount, 0);
        return helper(coins, amount, count);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1)
            return 0;
        
        vector<int> dp(amount + 1, 0);
        int sum = 1;
        while(sum <= amount){
            int minCoins = INT_MAX;
            for(int i = 0; i < coins.size(); i++){
                if(sum >= coins[i] && dp[sum - coins[i]] != -1){
                    int temp = dp[sum - coins[i]] + 1;
                    minCoins = min(minCoins, temp);
                }
            }
            dp[sum] = (minCoins == INT_MAX) ? -1 : minCoins;
            sum++;
        }

        return dp[amount];
    }
};

