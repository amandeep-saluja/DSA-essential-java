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
    TreeNode* builder(vector<int>& preorder, int pre_st, int pre_end, vector<int>& inorder, int in_st, int in_end) {
        if(pre_st>pre_end || in_st>in_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_st]);

        int in_root_idx;
        for(in_root_idx=0; in_root_idx<inorder.size(); in_root_idx++)
            if(inorder[in_root_idx]==root->val)
                break;
        int num_in_left = in_root_idx - in_st;
        int num_in_right = in_root_idx + 1 - in_end;

        root->left = builder(preorder, pre_st+1, in_root_idx-1, inorder, in_st, in_root_idx-1);
        root->right = builder(preorder, in_root_idx+1, p_end, inorder, in_root_idx+1, in_end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builder(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};