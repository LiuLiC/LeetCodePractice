/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> um;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                um[A[i] + B[j]]++;
            }
        }

        int result = 0;
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                int target = -(C[i] + D[j]);
                if(um.find(target) != um.end())
                    result += um[target];
            }
        }

        return result;
    }
};

