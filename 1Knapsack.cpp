 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int i=wt[0];i<=W;i++){
           dp[0][i]=val[0];
       }
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
               int notTake=dp[i-1][j];
               int take=INT_MIN;
               if(wt[i]<=j)
               take=val[i]+dp[i-1][j-wt[i]];
               dp[i][j]=max(take,notTake);
           }
           
       }
       return dp[n-1][W];
    }