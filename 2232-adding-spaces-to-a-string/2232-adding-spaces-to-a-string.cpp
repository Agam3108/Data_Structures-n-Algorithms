class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        int m = s.length();
        string ans =  "";
        int j = 0;
        for(int i = 0;i<m;i++){
           if(j<n && i==spaces[j]){
            ans += ' ';
            j++;
           }
           ans += s[i];
        }
        return ans;
    }
};