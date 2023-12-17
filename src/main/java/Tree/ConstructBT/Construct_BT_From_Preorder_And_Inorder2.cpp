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
    TreeNode* builder(vector<int>& preorder, int pre_st, int pre_end, vector<int>& inorder, int in_st, int in_end, unordered_map<int, int>& map) {
        if(pre_st>pre_end || in_st>in_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_st]);

        int in_root_idx = map[preorder[pre_st]];

        int num_in_left = in_root_idx - in_st;
        int num_in_right = in_root_idx + 1 - in_end;

        root->left = builder(preorder, pre_st + 1, pre_st + num_in_left, inorder, in_st, in_root_idx - 1, map);
        root->right = builder(preorder, pre_st + num_in_left + 1, pre_end, inorder, in_root_idx + 1, in_end, map);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = preorder.size();
        unordered_map<int, int> map;
        for(int i=0; i<p; i++) {
            map[inorder[i]] = i;
        }
        return builder(preorder, 0, p-1, inorder, 0, p-1, map);
    }
};