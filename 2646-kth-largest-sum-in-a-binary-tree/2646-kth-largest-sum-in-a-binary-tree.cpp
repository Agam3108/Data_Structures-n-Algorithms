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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root)
            return -1;
        vector<long long> levelSum;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            long long sum = 0;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                 TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            levelSum.push_back(sum);
           
        }
        int n = levelSum.size();
        //cout << n << endl;
        if (k > n)
            return -1;
        sort(levelSum.begin(), levelSum.end());
        return levelSum[n - k];
    }
};