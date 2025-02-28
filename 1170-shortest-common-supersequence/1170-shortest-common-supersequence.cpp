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
            s += str1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]){
         
            s += str2[j-1];
               j--;
            }
            else{
             s += str1[i-1];
            i--;
          
            }
        }
     }
      while(i>0){
        s+=str1[i-1];
        i--;
    }
    while(j>0){
    s+=str2[j-1];
    j--;
    }
     // reverse(s.begin(),s.end());
     return s;
}
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        string lcs = LCS(str1,str2,m,n);
       reverse(lcs.begin(),lcs.end());
        return lcs ;
    }
};