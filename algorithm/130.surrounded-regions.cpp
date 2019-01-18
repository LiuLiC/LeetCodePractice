/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (21.68%)
 * Total Accepted:    128.5K
 * Total Submissions: 592.3K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows == 0)
            return;
        int cols = board[0].size();

        if(rows < 3 || cols < 3)
            return;

        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            q.push(make_pair(i, 0));
            q.push(make_pair(i, cols - 1));
        }
        for(int j = 1; j < cols - 1; j++){
            q.push(make_pair(0, j));
            q.push(make_pair(rows - 1, j));
        }

        while(!q.empty()){
            pair<int, int> location = q.front();
            q.pop();
            int row = location.first, col = location.second;
            if(board[row][col] == 'O'){
                board[row][col] = '1';
                if(row > 0)
                    q.push(make_pair(row - 1, col));
                if(row < rows - 1)
                    q.push(make_pair(row + 1, col));
                if(col > 0)
                    q.push(make_pair(row, col - 1));
                if(col < cols - 1)
                    q.push(make_pair(row, col + 1));
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }

        return;
    }
};
