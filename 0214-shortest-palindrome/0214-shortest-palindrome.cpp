class Solution {
public:
    string shortestPalindrome(string s) {
        int n =s.length();
         string rev = string(s.rbegin(),s.rend());
         string combinedString = s+'#'+rev;
        vector<int> prefixTable =  buildPrefixTable(combinedString);
        int len = prefixTable[combinedString.length()-1];
        string suffix = rev.substr(0,n-len);
        
        return suffix+s;
    }
    private: 
    vector<int> buildPrefixTable(string s){
        vector<int> lps(s.length(),0);
        int n = s.length();
        lps[0]=0;
        for(int i = 1;i<n;i++){
          int len = lps[i-1];
          while(len>0 && s[i]!=s[len]){
            len = lps[len-1];
          }
          if(s[i]==s[len])
          len++;
          lps[i] = len;
        }
        return lps;
    }
};