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
    void preorderTraversalUtil(TreeNode* root, vector<int>& res) {
        //root
        res.push_back(root->val);
        //left
        if(root->left != NULL) preorderTraversalUtil(root->left, res);
        //right
        if(root->right != NULL) preorderTraversalUtil(root->right, res);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root!=NULL)
            preorderTraversalUtil(root, res);
        return res;
    }
};