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

    TreeNode* deepcopy(TreeNode* root) {
        if(root==NULL) return NULL;

        TreeNode* newRoot = new TreeNode(root->val);
        if(root->left != NULL) newRoot->left = deepcopy(root->left);
        if(root->right != NULL) newRoot->right = deepcopy(root->right);
        return newRoot;
    }

    void helper(vector<TreeNode*>& res, int n, TreeNode* root, TreeNode* base) {
        root->left = new TreeNode(0, NULL, NULL);
        root->right = new TreeNode(0, NULL, NULL);

        if(n-2 > 0) helper(res, n-2, root->left, base);

        root->left->left = root->left->right = NULL;

        if(n-2 > 0) helper(res, n-2, root->right, base);

        root->right->left = root->right->right = NULL;

        if(n-2 > 0){
            helper(res, (n-2)/2, root->left, base);
            helper(res, (n-2)/2, root->right, base);
        }

        if(n-2 == 0) {
            cout<<"pushing"<<endl;
            res.push_back(deepcopy(base));
            return;
        }
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if(n%2==0) return res;
        TreeNode* root = new TreeNode(0, NULL, NULL);
        if(n==1) {
            res.push_back(root);
            return res;
        }
        helper(res, n-1, root, root);
        return res;
    }
};