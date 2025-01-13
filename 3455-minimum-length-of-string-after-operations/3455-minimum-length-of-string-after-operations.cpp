class Solution {
public:
    int minimumLength(string s) {
    
    int n = s.length();
    int freqsum=0 ;
    unordered_map<char,int> mpp;
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    for(auto it: mpp){
        if(it.second%2)
        freqsum+=1;
        else
        freqsum+=2;

    }

    return freqsum;
}
  
};