/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (29.73%)
 * Total Accepted:    233.3K
 * Total Submissions: 784.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool continue_search(vector<vector<char>>& board, string word, 
                         int cur, vector<vector<bool>>& used, int i, int j){
        if(cur == word.size())
            return true;
        
        bool same = false;
        if(i > 0 && !used[i - 1][j] && board[i - 1][j] == word[cur]){
            used[i - 1][j] = true;
            same = continue_search(board, word, cur + 1, used, i - 1, j);
            used[i - 1][j] = false;
            if(same)
                return true;
        }

        if(i < board.size() - 1 && !used[i + 1][j] && board[i + 1][j] == word[cur]){
            used[i + 1][j] = true;
            same = continue_search(board, word, cur + 1, used, i + 1, j);
            used[i + 1][j] = false;
            if(same)
                return true;
        }

        if(j > 0 && !used[i][j - 1] && board[i][j - 1] == word[cur]){
            used[i][j - 1] = true;
            same = continue_search(board, word, cur + 1, used, i, j - 1);
            used[i][j - 1] = false;
            if(same)
                return true;
        }

        if(j < board[0].size() - 1 && !used[i][j + 1] && board[i][j + 1] == word[cur]){
            used[i][j + 1] = true;
            same = continue_search(board, word, cur + 1, used, i, j + 1);
            used[i][j + 1] = false;
            if(same)
                return true;
        }

        return same;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            if(word == "")
                return true;
            else
                return false;
        }

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        int cur = 0;
        bool result = false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[cur]){
                    used[i][j] = true;
                    result = continue_search(board, word, cur + 1, used, i, j);
                    used[i][j] = false;

                    if(result)
                        return true;
                }
            }
        }

        return false;
    }
};
