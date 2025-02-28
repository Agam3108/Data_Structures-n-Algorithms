class Solution {
public:
    int maxDepth(string s) {
      int n = s.length();
      int cnt = 0;
      int maxcount = 0;
      for(char c : s){
        if(c=='(')
        cnt++;
        else if(c==')')
        cnt--;
        maxcount = max(cnt,maxcount);
      }  
      return maxcount;
    }
};