class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.length();
        if(n == 1)
        return s;
        ans += s[0];
        for(int i = 1;i<n-1;i++){
            if(s[i] == s[i-1] && s[i] == s[i+1])
            continue;
            else 
            ans += s[i];
        }
        ans += s[n-1];
        return ans;
    }
};