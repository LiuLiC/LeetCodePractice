/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (36.25%)
 * Total Accepted:    180.2K
 * Total Submissions: 497K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
class Solution {
public:
    // BFS method
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            in[prerequisites[i].first]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int src = q.front();
            q.pop();
            for(int i = 0; i < graph[src].size(); i++){
                in[graph[src][i]]--;
                if(in[graph[src][i]] == 0)
                    q.push(graph[src][i]);
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(in[i] != 0)
                return false;
        }
        
        return true;
    }

    // DFS method
    bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visit(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }

        for(int i = 0; i < numCourses; i++){
            if(!canFinishDFS(graph, visit, i))
                return false;
        }

        return true;
    }

    bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int t){
        if(visit[t] == -1)
            return false;
        
        if(visit[t] == 1)
            return true;

        visit[t] = -1;
        for(auto i: graph[t]){
            if(!canFinishDFS(graph, visit, i))
                return false;
        }
        visit[t] = 1;

        return true;
    }
};
