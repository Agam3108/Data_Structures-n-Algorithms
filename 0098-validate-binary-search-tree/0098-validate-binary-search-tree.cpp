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
    bool isValidBST(TreeNode* root) {
        bool flag = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* fr = q.front();
            q.pop();
            if(!fr)
            continue;
            TreeNode* node;
            node = fr->left;
            while(node){
            if( node->val >= fr->val)
            return false;
            node = node->right;
            }
            node = fr->right;
            while(node){
            if( node->val <= fr->val)
            return false;
            node = node->left;
            }
           q.push(fr->left);
            q.push(fr->right);
        }
        return true;
    }
};