/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums1.size(); i++){
            um[nums1[i]]++;
        }
        vector<int> res;

        for(int num : nums2){
            if(um.find(num) != um.end() && um[num] > 0){
                res.push_back(num);
                um[num]--;
            }
        }

        return res;
    }
};

