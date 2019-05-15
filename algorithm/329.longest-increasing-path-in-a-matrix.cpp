/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */
class Solution
{
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>> &matrix){
        if (matrix.size() == 0)
            return 0;
        if (matrix[0].size() == 0)
            return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m, vector(n, 0));

        int maxLen = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int l = dfs(matrix, cache, i, j, m, n);
                maxLen = max(maxLen, l);
            }
        }

        return maxLen;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &cache,
            int i, int j, int m, int n){
        if (cache[i][j] != 0)
            return cache[i][j];

        int maxLen = 1;
        for (int k = 0; k < dirs.size(); k++){
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];

            if (x >= m || x < 0 || y >= n || y < 0 || matrix[i][j] >= matrix[x][y]){
                continue;
            }
            int l = dfs(matrix, cache, x, y, m, n) + 1;
            maxLen = max(l, maxLen);
        }

        cache[i][j] = maxLen;
        return maxLen;
    }
};
