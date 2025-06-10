class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        map<char,int> mp;
      
        int diff;
        int maxdiff = INT_MIN ;
        for(int i =0;i<n;i++){
            mp[s[i]]++;
        }
       // for(int i =0;i<n;i++){
         //   char ch = s[i];
             for(auto it = mp.begin();it!=mp.end();it++){
            
                 int freq = it->second;
                  for( auto it2 = next(it); it2!=mp.end();it2++) {
                
                 int freq2 = it2->second;
                 if(freq2 %2 == 0 && freq%2==1 )
                      maxdiff = max(freq-freq2,maxdiff);
                 else if( freq2 %2 == 1 && freq%2==0)
                      maxdiff = max(freq2-freq,maxdiff);
                   
                      
        }
         
             }
       return maxdiff;
    }
};