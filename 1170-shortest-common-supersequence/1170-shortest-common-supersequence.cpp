class Solution {
public:
int dp[1001][1001];
string LCS(string str1,string str2,int m,int n){
     for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
     }
      int i = m;
     int j = n;
     string s = "";
     while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            s.push_back(str1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j])
            j--;
            else
            i--;
        }
     }
      reverse(s.begin(),s.end());
     return s;
}
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        string lcs = LCS(str1,str2,m,n);
        string sup = str1+str2;
        int ind = sup.find(lcs);
        sup.erase(ind,lcs.size());
        return sup ;
    }
};