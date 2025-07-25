class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        int len = 0; //length of previous longest suffix prefix
        vector<int> lps(n,0); //longest prefix suffix;
        for(int i = 1;i<n;i++){
            while(len>0 &&  s[i]!=s[len]){
                len = lps[len-1];
            }
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
            }
        }


        return s.substr(0,lps[n-1]);
    }
};