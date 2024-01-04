#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<TreeNode*> allPossibleFBT(int n) {
        std::vector<TreeNode*> result;

        if (n % 2 == 0) {
            // Even number of nodes cannot form a full binary tree
            return result;
        }

        if (n == 1) {
            // Special case: a single node forms a full binary tree
            result.push_back(new TreeNode(0));
            return result;
        }

        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
            std::vector<TreeNode*> leftSubtrees = allPossibleFBT(leftNodes);
            std::vector<TreeNode*> rightSubtrees = allPossibleFBT(n - 1 - leftNodes);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};

// Helper function to print the tree (in-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

int main() {
    Solution solution;

    // Example 1
    int n1 = 7;
    std::vector<TreeNode*> result1 = solution.allPossibleFBT(n1);
    for (TreeNode* root : result1) {
        printTree(root);
        std::cout << std::endl;
    }

    // Example 2
    int n2 = 3;
    std::vector<TreeNode*> result2 = solution.allPossibleFBT(n2);
    for (TreeNode* root : result2) {
        printTree(root);
        std::cout << std::endl;
    }

    return 0;
}
