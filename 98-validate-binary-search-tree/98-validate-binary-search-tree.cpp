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
    vector<int> traversal;
    void inOrder(TreeNode* node) {
        if(!node) return;
        inOrder(node->left);
        traversal.push_back(node->val);
        inOrder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        inOrder(root);
        for(int i=1; i<traversal.size(); i++) {
            if(traversal[i-1]>=traversal[i])
                return false;
        }
        return true;
    }
};