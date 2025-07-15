class Solution {
public:
//long long t[301][5001];
const int mod = 1e9+7;
    int change(int amount, vector<int>& coins) {
          int n = coins.size();
        // use 64-bit unsigned integer to safely store large counts
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(amount + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return static_cast<int>(dp[n][amount]);
    }
};