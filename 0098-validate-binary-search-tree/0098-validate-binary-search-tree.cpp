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
bool ValidateBST(TreeNode* root,long long l,long long u){
    if(!root)
    return true;
    if(root->val >= u || root->val <= l )
    return false;
    return ValidateBST(root->left,l,root->val) && ValidateBST(root->right,root->val,u);
}
    bool isValidBST(TreeNode* root) {
      return ValidateBST(root,LLONG_MIN,LLONG_MAX);
    }
};