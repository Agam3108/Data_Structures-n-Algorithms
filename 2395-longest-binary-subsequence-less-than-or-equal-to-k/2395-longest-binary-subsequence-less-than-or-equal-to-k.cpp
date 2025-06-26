class Solution {
public:
// int dp[1001][1001];
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int countZeros = 0;
        int count = 0;
        int value = 0;
        int power = 0;
        for(int i = n-1;i>=0;i--){
            char c = s[i];
            if(c == '0'){
            countZeros++;
            power++;
            }
            else{
                if(value + pow(2,power) <= k){
                    value += pow(2,power);
                    count++;
                    power++;
                }
            }
        }
       return count + countZeros ;    
    }
};