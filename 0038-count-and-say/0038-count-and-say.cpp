class Solution {
public:
string findRLE(string s){
   int i = 0;
        int len = s.length();
        string ans;
        while (i < len) {
            int j = i;
            while (i < len && s[i] == s[j]) {
                ++i;
            }
            ans += to_string(i - j) + s[j]; 
        }
        return ans;
}
    string countAndSay(int n) {
       if (n == 1) {
            return "1";
        }
        string ans = "1"; 
        for (int i = 2; i <= n; i++) {
            ans = findRLE(ans);  
        }
        return ans;
    }
};