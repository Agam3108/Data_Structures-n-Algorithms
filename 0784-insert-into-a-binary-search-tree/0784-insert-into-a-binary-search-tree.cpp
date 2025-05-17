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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        return new TreeNode(val);
        TreeNode* copy=root;
        while(true){
            if(copy->val<=val){
                if(copy->right!=NULL)
                copy=copy->right;
                else{
              copy->right=new TreeNode(val);
                break;
                }
            }
            else{
                if(copy->left!=NULL)
                copy=copy->left;
                else{
                  copy->left=new TreeNode(val);
                  break;
                }
            }
        }
        return root;
    }
};