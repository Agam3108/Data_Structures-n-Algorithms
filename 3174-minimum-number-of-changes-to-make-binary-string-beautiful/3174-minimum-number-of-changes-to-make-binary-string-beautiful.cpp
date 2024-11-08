class Solution {
public:
    int minChanges(string s) {
       int n = s.length();
       int minChanges = 0;
        for(int i = 0;i<n;i=i+2){
           string str = s.substr(i,2);
            if(str[0] == '0' && str[1]=='1' || str[1]=='0' && str[0]=='1')
            minChanges++;
            else
            continue;
        }
        return minChanges;
    }
};