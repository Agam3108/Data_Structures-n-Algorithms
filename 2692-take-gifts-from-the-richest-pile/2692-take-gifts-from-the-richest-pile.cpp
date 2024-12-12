class Solution {
public:
const double mod = 1e9+7;
    long long pickGifts(vector<int>& gifts, int k) {
        int n  = gifts.size();
        long long res = 0;
        while(k--){
           sort(gifts.begin(),gifts.end());
           gifts[n-1]= sqrt(gifts[n-1]);

        }
        for(int i = 0;i<n;i++){
            res += (long long) gifts[i] ;
        }
        return res;
    }
};