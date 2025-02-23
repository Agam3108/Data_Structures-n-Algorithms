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
TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int> &postorder,int postStart,int postEnd){
    if(preStart>preEnd)
    return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    if(preStart ==preEnd)
    return root;

    int left_root = preorder[preStart+1];
    int i = postStart;
    while(i<=postEnd){
        if(postorder[i]==left_root)
        break;
        i++;
    }
    int l = i-postStart+1;
    root->left = build(preorder,preStart+1,preStart+l,postorder,postStart,i);
    root->right = build(preorder,preStart+l+1,preEnd,postorder,i+1,postEnd-1);
    return root;

}


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder,0,n-1,postorder,0,n-1);
        return nullptr;

    }
};