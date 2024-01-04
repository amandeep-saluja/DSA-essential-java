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
    vector<TreeNode*> allPossibleFBTWithMemo(int n, unordered_map<int, vector<TreeNode*>>& mp) {
        vector<TreeNode*> res;

        if(n%2==0) return res;

        if(mp.find(n) != mp.end()) {
            cout<<"using map for "<<n<<endl;
            return mp[n];
        }

        if(n==1) {
            res.push_back(new TreeNode(0));
            cout<<"pushing 1"<<endl;
            return mp[1] = res;
        }

        for(int leftNodes=1; leftNodes < n; leftNodes+=2){
            vector<TreeNode*> leftSubTree = allPossibleFBTWithMemo(leftNodes, mp);
            vector<TreeNode*> rightSubTree = allPossibleFBTWithMemo(n - 1 - leftNodes, mp);

            for(TreeNode* leftNode : leftSubTree) {
                for(TreeNode* rightNode : rightSubTree) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftNode;
                    root->right = rightNode;
                    res.push_back(root);
                }
            }
        }

        return mp[n] = res;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> mp;
        return allPossibleFBTWithMemo(n, mp);
    }
};