/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (27.19%)
 * Total Accepted:    95.4K
 * Total Submissions: 350.1K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * Example:
 * 
 * 
 * Input: 
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */
class Solution {
public:
    class TrieNode {
        public:
            vector<TrieNode*> links;
            string isWord;

            TrieNode() : isWord("") {
                links = vector<TrieNode*>(26, NULL);
            }
    };

    TrieNode* buildTrie(vector<string>& words){
        TrieNode *root = new TrieNode();
        for(auto word: words){
            TrieNode *cur = root;
            for(auto ch: word){
                if(cur->links[ch - 'a'] == NULL){
                    cur->links[ch - 'a'] = new TrieNode();
                }
                cur = cur->links[ch - 'a'];
            }

            cur->isWord = word;
        }

        return root;
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<string>& result, TrieNode* node){
        char ch = board[i][j];
        if(ch == '#' || node->links[ch - 'a'] == NULL)
            return;
        
        node = node->links[ch - 'a'];
        if(node->isWord != ""){
            result.push_back(node->isWord);
            node->isWord = "";
        }

        board[i][j] = '#';
        if(i > 0)
            dfs(i - 1, j, board, result, node);
        if(j > 0)
            dfs(i, j - 1, board, result, node);
        if(i < board.size() - 1)
            dfs(i + 1, j, board, result, node);
        if(j < board[0].size() - 1)
            dfs(i, j + 1, board, result, node);
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(i, j, board, result, root);
            }
        }

        return result;
    }
};
