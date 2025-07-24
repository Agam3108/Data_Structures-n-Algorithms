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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root)
        return {};
        deque<TreeNode*> q;
        q.push_back(root);
        
        while(!q.empty()){
            TreeNode* fr = q.back();
            q.pop_back();
            preorder.push_back(fr->val);
               if(fr->right)
            q.push_back(fr->right);
            if(fr->left)
            q.push_back(fr->left);
         
        }
      return preorder;
    }
};