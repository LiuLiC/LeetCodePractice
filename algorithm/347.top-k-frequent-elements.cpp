/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]]++;
        }

        vector<pair<int, int>> v;
        for(auto it = um.begin(), ite = um.end(); it != ite; it++){
            v.push_back(make_pair(it->first, it->second));
        }

        sort(v.begin(), v.end(), comp);
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }

        return res;
    }
};

