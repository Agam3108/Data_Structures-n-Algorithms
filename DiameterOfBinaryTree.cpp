int height(TreeNode* root,int &maxi){
    if(root==NULL)
    return 0;
    int lh=height(root->left,maxi);
    int rh=height(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
      height(root,maxi);
        return maxi;
    }