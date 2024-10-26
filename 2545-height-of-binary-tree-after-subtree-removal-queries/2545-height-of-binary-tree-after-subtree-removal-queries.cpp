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
    void dfs(TreeNode* root, int height, vector<int>& eulerTour,
             unordered_map<int, int>& nodeHeights,
             unordered_map<int, int>& firstOccurrence,
             unordered_map<int, int>& lastOccurrence) {
        if (root == nullptr)
            return;

        nodeHeights[root->val] = height;
        firstOccurrence[root->val] = eulerTour.size();
        eulerTour.push_back(root->val);

        dfs(root->left, height + 1, eulerTour, nodeHeights, firstOccurrence,
            lastOccurrence);
        dfs(root->right, height + 1, eulerTour, nodeHeights, firstOccurrence,
            lastOccurrence);

        lastOccurrence[root->val] = eulerTour.size();
        eulerTour.push_back(root->val);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> eulerTour;
        unordered_map<int, int> nodeHeights, firstOccurrence, lastOccurrence;
        dfs(root, 0, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);

        int tourSize = eulerTour.size();
        vector<int> maxDepthLeft(tourSize), maxDepthRight(tourSize);
        maxDepthLeft[0] = maxDepthRight[tourSize - 1] = nodeHeights[root->val];
        for (int i = 1; i < tourSize; i++) {
            maxDepthLeft[i] =
                max(maxDepthLeft[i - 1], nodeHeights[eulerTour[i]]);
        }

        for (int i = tourSize - 2; i >= 0; i--) {
            maxDepthRight[i] =
                max(maxDepthRight[i + 1], nodeHeights[eulerTour[i]]);
        }
        vector<int> results(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int queryNode = queries[i];
            int leftMax = (firstOccurrence[queryNode] > 0)
                              ? maxDepthLeft[firstOccurrence[queryNode] - 1]
                              : 0;
            int rightMax = (lastOccurrence[queryNode] < tourSize - 1)
                               ? maxDepthRight[lastOccurrence[queryNode] + 1]
                               : 0;
            results[i] = max(leftMax, rightMax);
        }

        return results;
    }
};