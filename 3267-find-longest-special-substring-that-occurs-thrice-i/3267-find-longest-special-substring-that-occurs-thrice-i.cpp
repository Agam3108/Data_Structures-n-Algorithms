class Solution {
public:
bool isSpecial(string s){
    int n = s.length();
    map<char,int> mp;
    for( char c: s){
        mp[c]++;
    }
    if(mp.size()==1)
    return true;
    return false;
}
    int maximumLength(string s) {
        int n = s.length();
        map<string,int> freq;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                string str = s.substr(i,j-i+1) ;
                if(isSpecial(str))
                    freq[str]++;
                
            }
        }
  
        int res = 0;
        
        for(const auto it : freq){
            if(it.second >= 3){
                if(it.first.length()>res)
                res = it.first.length();
            }
        }
     int ans =  res == 0 ? -1 : res;
     return ans;
  
    }
};