class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        string copy = s;
        while(copy.find("AB")!=-1 || copy.find("CD")!=-1){
          if(copy.find("AB")!=-1){
            copy.erase(copy.find("AB"),2);
          }
          else if(copy.find("CD") != -1){
            copy.erase(copy.find("CD"),2);
          }
        }
        return copy.length();
    }
};