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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int level = q.size();
            vector<int> levels;
            while(level) {
                TreeNode* node = q.front(); q.pop();
                levels.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level--;
            }
            result.push_back(levels);
        }
        return result;
    }
};