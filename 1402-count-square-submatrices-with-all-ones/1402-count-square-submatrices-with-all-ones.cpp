class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int countOfOnes = 0;
        vector<vector<int>> dp(n,vector<int>(m,1));
         dp[0][0] = 1;
         for(int i = 0;i<n;i++)
         dp[i][0] = matrix[i][0];
         for(int j = 0;j<m;j++)
         dp[0][j] = matrix[0][j];
         for(int i =1;i<n;i++){
            for(int j =1;j<m;j++){
                if(matrix[i][j]==1)
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                else
                dp[i][j] = 0;
            }
         }
         int countSubMatrices = 0;
         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                countSubMatrices += dp[i][j];
            }
         }
         return countSubMatrices;

    }
};