 bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
        return maxHeight(root)!=-1;
    }
    int maxHeight(TreeNode* root){
        if(root==NULL) return 0;
     int lh=maxHeight(root->left);
     int rh=maxHeight(root->right);
     if(lh==-1 || rh==-1)
     return -1;
     if(abs(lh-rh)>1)
     return -1;
     return 1+max(lh,rh);

    }