/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (53.92%)
 * Total Accepted:    380.2K
 * Total Submissions: 705K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Recursive method :
    // void traversal(TreeNode* node, vector<int>& result){
    //     if(node != NULL){
    //         traversal(node->left);
    //         result.push_back(node->val);
    //         traversal(node->right);
    //     }
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traversal(root, result);
    //     return result;
    // }
};
