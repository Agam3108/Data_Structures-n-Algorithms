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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
        return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> levelOrder;
        vector<int> ans;
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            for(int i =0;i<s;i++){
               TreeNode* node = q.front();
               q.pop();
               level.push_back(node->val);
               if(node->left)
               q.push(node->left);
               if(node->right)
               q.push(node->right);
            }
            levelOrder.push_back(level);
        }
       for(int i =0;i<levelOrder.size();i++){
        ans.push_back(*max_element(levelOrder[i].begin(),levelOrder[i].end()));
       }
       return ans;
    }
};