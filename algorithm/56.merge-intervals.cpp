/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (33.92%)
 * Total Accepted:    277.8K
 * Total Submissions: 815.8K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(const Interval &a, const Interval &b){
        return a.start <= b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size() == 0)
            return result;

        sort(intervals.begin(), intervals.end(), comp);

        int j = 0;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){    
            if(result[j].end >= intervals[i].start){
                result[j].end = max(result[j].end, intervals[i].end);
            }
            else{
                result.push_back(intervals[i]);
                j++;
            }
        }

        return result;
    }
};
