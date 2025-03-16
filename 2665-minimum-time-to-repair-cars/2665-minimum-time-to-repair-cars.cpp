class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
     
        int minRank = *min_element(ranks.begin(),ranks.end());
        int maxRank = *max_element(ranks.begin(),ranks.end());
        long long hi = 1LL*minRank*cars*cars;
        long long lo = 1;
        vector<int> freqArray(maxRank+1);
        for(int i =0;i<n;i++)
        freqArray[ranks[i]]++;
        while(lo < hi){
            long long mid = lo+(hi-lo)/2;
            long long ans = 0;
            for(int rank = 1;rank<=maxRank;rank++){
               ans += freqArray[rank]*(long long)sqrt(mid/(long long)rank);
            }
              if (ans >= cars) {
                hi = mid; 
            } else {
                lo = mid + 1;  
            }
        }
      return lo;
    }
};