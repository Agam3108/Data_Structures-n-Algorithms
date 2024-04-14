 int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==NULL)
        return 0;
        if(root!=NULL){
        if(isLeafNode(root->left)==true)
          {
            sum+=root->left->val;
          }
          else{
            sum+=sumOfLeftLeaves(root->left);
          }
          sum+=sumOfLeftLeaves(root->right);
        }
        return sum;
    }
    bool isLeafNode(TreeNode* root){
        if(root==NULL)
        return false;
        if(root->left==NULL && root->right==NULL)
        return true;
        return false;

    }