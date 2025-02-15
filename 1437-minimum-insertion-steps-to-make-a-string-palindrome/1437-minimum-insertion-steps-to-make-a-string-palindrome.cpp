class Solution {
public:
int dp[501][501];
int LCS(string a,string b,int n){
    for(int i =0;i<=n;i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(a[i-1]==b[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
    int longestPalindromeSubseq(string s) {
       int n = s.length();
       string a = s;
       reverse(s.begin(),s.end());
       return LCS(a,s,n);
    }
    int minInsertions(string s) {
        int n = s.length();
        int lps = longestPalindromeSubseq(s);
        return n - lps;
    }
};