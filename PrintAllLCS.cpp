void backtrack(const vector<vector<int>>& dp, const string& s, const string& t, int i, int j, string& current, unordered_set<string>& lcsSet) {
    // Base case: we've reached the beginning of either string
    if (i == 0 || j == 0) {
        reverse(current.begin(), current.end());
        lcsSet.insert(current);
        reverse(current.begin(), current.end());
        return;
    }
    
    if (s[i-1] == t[j-1]) {
        // If characters match, include this character in the current LCS
        current.push_back(s[i-1]);
        backtrack(dp, s, t, i-1, j-1, current, lcsSet);
        current.pop_back();
    } else {
        // If characters don't match, we need to explore both possible paths
        if (dp[i-1][j] == dp[i][j]) {
            backtrack(dp, s, t, i-1, j, current, lcsSet);
        }
        if (dp[i][j-1] == dp[i][j]) {
            backtrack(dp, s, t, i, j-1, current, lcsSet);
        }
    }
}
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		     int n=s.size();
        int m=t.size();
        vector<string> vec;
        string str="";
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        }
       
         unordered_set<string> lcsSet;
    string current;
    backtrack(dp, s, t, n, m, current, lcsSet);
    
    // Convert set to vector and sort in lexicographical order
    vector<string> result(lcsSet.begin(), lcsSet.end());
    sort(result.begin(), result.end());
    return result;
		}