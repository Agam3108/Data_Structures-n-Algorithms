class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int openingBrackets = 0;
        int rem = 0;
        for(char ch : s){
            if(ch == '(')
            openingBrackets++;
            else
            openingBrackets > 0 ? openingBrackets-- : rem++;
        }
        return rem + openingBrackets ;
    }
};