/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0), t;
        if(nums.size() == 0)
            return result;

        for(int i = nums.size() - 1; i >= 0; i--){
            int val = nums[i];
            int left = 0, right = t.size() - 1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(t[mid] >= val)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            result[i] = left;
            t.insert(t.begin() + left, val);
        }

        return result;
    }
};

