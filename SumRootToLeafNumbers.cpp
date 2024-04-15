 int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode* root,int curr_sum){
        if(root==NULL)
        return 0;
        curr_sum=curr_sum*10+root->val;
        if(!root->left && !root->right)
        return curr_sum;
       return dfs(root->left,curr_sum)+dfs(root->right,curr_sum);
    }