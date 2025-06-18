class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        if(a == b)
        return 1;
        string src = a;
        int count = 1;
        while(src.length() < m){
            count++;
            src += a;
        }
        if(src == b)
        return count;
        if(f(src,b)!=-1)
        return count;
        if(f(src+a,b)!=-1)
        return count+1;
        return -1;
    }
    int f(string text, string pattern){
         int n = text.length();
      int m = pattern.length();

      int j;
      for (int i = 0; i <= n - m; i++) {

        for (j = 0; j < m; ++j) {
          if (pattern[j] != text[i + j]) {
            break;
          }
        }

        if (j == m) {
          return i;
        }
      }
      return -1;
    }
};