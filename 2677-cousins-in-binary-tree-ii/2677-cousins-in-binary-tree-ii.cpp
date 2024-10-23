/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return nullptr;
        vector<int> levelSum;
        int depth = 0;
        int sum;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            sum = 0;
            while (s--) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            levelSum.push_back(sum);
        }
        levelSum.push_back(levelSum.back());
        q.push(root);
        root->val = 0;
        while (!q.empty()) {
            depth++;
            int s = q.size();
            while (s--) {
                sum = levelSum[depth];
                auto node = q.front();
                q.pop();
                if (node->left) {
                    sum -= node->left->val;
                    q.push(node->left);
                }

                if (node->right) {
                    sum -= node->right->val;
                    q.push(node->right);
                }
                if (node->left)
                    node->left->val = sum;
                if (node->right)
                    node->right->val = sum;
            }
        }

        return root;
    }
};