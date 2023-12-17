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
        int sum=0;
        if(root->left==NULL && root->right==NULL)
            sum+= (10*currSum+root->val);

        if(root->left != NULL) sum+= sumUtil(root->left, 10*currSum + root->val);
        if(root->right != NULL) sum+= sumUtil(root->right, 10*currSum + root->val);

        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumUtil(root, 0);
    }
};