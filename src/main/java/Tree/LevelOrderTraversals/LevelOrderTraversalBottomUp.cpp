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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        stack<vector<int>> stack;

        while(!q.empty()) {
            vector<int> currLevel;
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                currLevel.push_back(currNode->val);
                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }
            stack.push(currLevel);
        }
        while(!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        return res;
    }
};