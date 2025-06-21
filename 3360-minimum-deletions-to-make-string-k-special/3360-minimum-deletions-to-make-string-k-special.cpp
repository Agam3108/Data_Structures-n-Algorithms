class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        unordered_map<char,int> mpp;
        for(char c : word){
           mpp[c]++;
        }
        int ans = n;
        for(int i = 0;i<n;i++){
           char c = word[i];
           int x = mpp[c];
           int res = 0;
           for(const auto it : mpp){
            if(it.first != c){
                int y = it.second;
                if(y < x){
                    res += y;
                }
                else if(y > x+k){
                    res += y-(x+k);
                }
            }
           }
           ans = min(ans,res);
        }
        return ans;
    }
};