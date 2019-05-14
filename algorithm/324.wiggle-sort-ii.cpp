/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n;
        sort(temp.begin(), temp.end());

        for(int i = 0; i < n; i++){
            nums[i] = (i % 2) ? temp[--j] : temp[--k]; 
        }
    }
};

