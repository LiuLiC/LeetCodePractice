/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (36.91%)
 * Total Accepted:    135.4K
 * Total Submissions: 366.9K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 */
class Solution {
public:
    // Use Multiset
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     multiset<int> window;
    //     vector<int> result;

    //     if(nums.empty())
    //         return result;

    //     int i;
    //     for(i = 0; i < k; i++){
    //         window.insert(nums[i]);
    //     }
    //     result.push_back(*window.rbegin());

    //     for(; i < nums.size(); i++){
    //         window.erase(window.find(nums[i - k]));
    //         window.insert(nums[i]);
    //         result.push_back(*window.rbegin());
    //     }

    //     return result;
    // }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;

        for(int i = 0; i < nums.size(); i++){
            if(!q.empty() && q.front() == i - k)
                q.pop_front();

            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();

            q.push_back(i);

            if(i >= k - 1){
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
