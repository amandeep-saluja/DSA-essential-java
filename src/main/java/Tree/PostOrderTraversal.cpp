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
    void postorderTraversalUtil(TreeNode* root, vector<int>& res) {
        //left
        if(root->left != NULL) postorderTraversalUtil(root->left, res);
        //right
        if(root->right != NULL) postorderTraversalUtil(root->right, res);
        //root
        res.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root!=NULL)
            postorderTraversalUtil(root, res);
        return res;
    }
};