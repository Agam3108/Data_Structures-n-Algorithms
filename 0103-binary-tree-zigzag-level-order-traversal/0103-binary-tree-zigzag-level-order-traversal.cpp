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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
        return {} ;
        vector<vector<int>> levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            for(int i = 0;i<s;i++){
                TreeNode* fr = q.front();
                q.pop();
                level.push_back(fr->val);
                if(fr->left)
                q.push(fr->left);
                if(fr->right)
                q.push(fr->right);
            }
            levelOrder.push_back(level);
        }
        for(int i = 0;i<levelOrder.size();i++){
            if(i%2==1){
                reverse(levelOrder[i].begin(),levelOrder[i].end());
            }
        }
        return levelOrder;
    }
};