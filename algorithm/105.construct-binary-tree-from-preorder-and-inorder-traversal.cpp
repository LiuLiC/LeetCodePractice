/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (38.55%)
 * Total Accepted:    189.4K
 * Total Submissions: 491.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* build(int pre_start, int in_start, int in_end, vector<int>& preorder, vector<int>& inorder){
        if(pre_start >= preorder.size() || in_start > in_end)
            return NULL;

        int cur_val = preorder[pre_start];
        TreeNode* cur = new TreeNode(cur_val);
        int index;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == cur_val){
                index = i;
                break;
            }
        }

        cur->left = build(pre_start + 1, in_start, index - 1, preorder, inorder);
        cur->right = build(pre_start + index - in_start + 1, index + 1, in_end, preorder, inorder);

        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, 0, inorder.size() - 1,preorder, inorder);
    }
};
