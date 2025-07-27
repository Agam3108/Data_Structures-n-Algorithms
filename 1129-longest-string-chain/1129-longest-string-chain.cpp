class Solution {
public:
static bool cmp(string &a,string &b){
    return a.length() < b.length() ;

}
bool canPossible(string &wrd1, string &wrd2){
   if(wrd1.size() != wrd2.size()+1)
   return false;
   int first = 0;
   int second = 0;
   while(first < wrd1.size()){
     if(wrd1[first] == wrd2[second]){
        first++;
        second++;
     }
     else
     first++;
   }
   if(first == wrd1.size() && second == wrd2.size())
   return true;
   return false;
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),cmp);
        for(int i = 1;i<n;i++){
           
            for(int j = 0;j<i;j++){
                if(canPossible(words[i],words[j]) && dp[i] < 1+dp[j] ){
                    dp[i] = 1 + dp[j];
                    
                }
            }
        }
        sort(dp.begin(),dp.end());
        return dp[n-1];
    }
};