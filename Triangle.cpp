 int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int dp[n][n];
    for(int j = 0; j < n; j++) {
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i = n-2; i >= 0; i--) {
        int down = 0; 
        int diag = 0;
        for(int j = i; j >= 0; j--) {
            down = triangle[i][j] + dp[i+1][j];
            diag = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diag);
        }
    }
    return dp[0][0];
}