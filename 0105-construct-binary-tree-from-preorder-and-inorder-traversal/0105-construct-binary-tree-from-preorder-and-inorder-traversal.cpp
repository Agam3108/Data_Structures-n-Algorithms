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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> inOrderMap;
        for(int i = 0; i < inorder.size(); i++){
            inOrderMap[inorder[i]] = i;
        }
        TreeNode* root = buildTree(0,n-1,inorder,0,n-1,preorder,inOrderMap);
        return root;
    }
    TreeNode* buildTree(int inStart,int inEnd,vector<int> &inorder,int preStart,int preEnd,vector<int> & preorder,unordered_map<int,int> &inOrderMap){
        if(preStart > preEnd || inStart > inEnd)
        return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inOrderMap[root->val];
        int numsLeft = inRoot-inStart;
        root->left = buildTree(inStart,inRoot-1,inorder,preStart+1,preStart+numsLeft,preorder,inOrderMap);
        root->right=buildTree(inRoot+1,inEnd,inorder,preStart+numsLeft+1,preEnd,preorder,inOrderMap);
        return root;
    }
};