/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sumUtil(TreeNode* root, int currSum) {
        if(root == NULL) return 0;

        if(root->left != NULL || root->right != NULL)
            return (sumUtil(root->left, currSum*10 + root->val) + sumUtil(root->right, currSum*10 + root->val));

        return currSum*10 + root->val;
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumUtil(root, 0);
    }
};