class Solution {
public:
    int numWays(vector<string>& words, string target) {
       int n = target.size();
        int m = words[0].size();
        const int MOD = 1000000007;
      
        vector<vector<int>> freq(26, vector<int>(m));
        for (int col = 0; col < m; col++) {
            for (const string& word : words) {
                freq[word[col] - 'a'][col]++;
            }
        }
        
        // DP table
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        dp[0][0] = 1;
        
        for (int j = 0; j < m; j++) {
            for (int i = 0; i <= n; i++) {
                // Carry over the previous dp values
                if (i < n) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (dp[i][j] * freq[target[i] - 'a'][j]) % MOD) % MOD;
                }
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
        
        return dp[n][m];
    }
};