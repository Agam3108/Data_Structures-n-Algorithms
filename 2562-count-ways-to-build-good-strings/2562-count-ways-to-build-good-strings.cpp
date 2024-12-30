class Solution {
public:
const int MOD = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1);
        dp[0] = 1;
        for(int end = 1 ;end <=high;end++){
            if(end>=zero)
            dp[end] += dp[end-zero];
            if(end >= one)
            dp[end] += dp[end-one];
            dp[end] %= MOD;

        }
        int sum = 0;
        for(int i = low;i<=high;i++) {
        sum += dp[i];
        sum %= MOD;
        }
        return sum;
    }
};