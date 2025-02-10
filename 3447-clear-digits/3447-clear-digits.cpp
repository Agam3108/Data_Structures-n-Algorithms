class Solution {
public:
bool isLetter(char ch){
     if(ch-'0' >=97 && ch-'0'<=122)
     return true;
     return false;
}
bool isDigit(char ch){
    if(ch-'0' >=0 && ch-'0' <=9)
    return true;
    return false;
}
    string clearDigits(string s) {
       int n = s.length();
       int l = 0;
       while(l<n){
        if(isDigit(s[l])) {
        s.erase(l,1);
        if(l>0){
            s.erase(l-1,1);
            l--;
        }
        }
        else
        l++;
       }
       return s;
    }
};