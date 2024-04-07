int Solve(Node*root,int &res){
        if(root==NULL)
        return 0;
        int left=max(0,Solve(root->left,res));
        int right=max(0,Solve(root->right,res));
        res=max(res,root->data+left+right);
        return root->data+max(left,right);
        
        
    }
    
        
        int findMaxSum(Node* root)
    {
        // Your code goes here
      int res=INT_MIN;
      Solve(root,res);
      return res;
    }