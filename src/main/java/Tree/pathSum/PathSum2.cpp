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

    void helper(vector<vector<int>>& res, vector<int>& curr, TreeNode* root, int sum) {
        //if(root==NULL) return;
        curr.push_back(root->val);

        if(root->left == NULL && root->right == NULL && (sum == root->val))
            res.push_back(curr);

        //left node
        if(root->left != NULL) helper(res, curr, root->left, sum - root->val);
        if(root->right != NULL) helper(res, curr, root->right, sum - root->val);
        curr.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curr;
        // Now helper will always be called for Non Null values only
        if(root != NULL)
            helper(res, curr, root, targetSum);
        return res;
    }
};