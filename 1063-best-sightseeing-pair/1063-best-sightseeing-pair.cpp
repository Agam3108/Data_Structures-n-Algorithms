class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
         int n = values.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = values[0];
        int maxscore = INT_MIN;
        for (int i = 1; i < n; ++i) {
            int currRight = values[i] - i;
            maxscore = max(maxscore,dp[i-1]+currRight);
            int currLeft = values[i] + i;
            dp[i] = max(dp[i-1],currLeft);
        }
        return maxscore;
        
    }
};