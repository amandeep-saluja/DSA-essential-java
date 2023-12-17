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
    TreeNode* buildTreeUtil(vector<int>& inorder, int in_st, int in_end, vector<int>& postorder, int post_st, int post_end, unordered_map<int, int>& map) {
        if(in_st>in_end || post_st>post_end) return NULL;

        TreeNode* root = new TreeNode(postorder[post_end]);

        int in_root_idx = map[postorder[post_end]];
        int num_in_left = in_root_idx-in_st;

        root->left  = buildTreeUtil(inorder, in_st, in_root_idx-1, postorder, post_st, post_st+num_in_left-1, map);
        root->right = buildTreeUtil(inorder, in_root_idx + 1, in_end, postorder, post_st+num_in_left, post_end-1, map);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> map;
        for(int i=0; i<n; i++)
            map[inorder[i]] = i;
        return buildTreeUtil(inorder, 0, n-1, postorder, 0, n-1, map);
    }
};