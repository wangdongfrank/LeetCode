/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node 
down to the farthest leaf node.

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root)
        return 0;
        int leftmax = maxDepth(root->left);
        int rightmax = maxDepth(root->right);
        return max(leftmax,rightmax)+1; 
    }
};
