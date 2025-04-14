class Solution {
public:
int memo[101][101];
int n;
 bool f(string& s, int ind, int count) {
        if (count < 0) return false;         
        if (ind == n) return (count == 0);  

        if (memo[ind][count] != -1) return memo[ind][count];

        bool res = false;
        if (s[ind] == '(') {
            res = f(s, ind + 1, count + 1);
        } else if (s[ind] == ')') {
            res = f(s, ind + 1, count - 1);
        } else { // s[ind] == '*'
            res = f(s, ind + 1, count + 1)  
               || f(s, ind + 1, count - 1)   
               || f(s, ind + 1, count);    
        }

        return memo[ind][count] = res;
    }
    bool checkValidString(string s) {
       n = s.length();
        memset(memo,-1,sizeof(memo));
       return f(s,0,0);
        
    }
};