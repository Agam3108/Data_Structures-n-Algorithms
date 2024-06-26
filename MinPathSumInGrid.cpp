 int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
      int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(i==0 && j==0){
            dp[i][j]=grid[0][0];
             }
        else{
            int up=1e9;int left=1e9;
            if(j>0)
            left=grid[i][j]+dp[i][j-1];
           if(i>0)
            up=grid[i][j]+dp[i-1][j];
            dp[i][j]=min(up,left);
        }
            }
        }
        return dp[n-1][m-1];
    }