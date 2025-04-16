class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
     
        int l = 0;
        int r = 0;
        long long ans = 0;
         long long count = 0;
        unordered_map<int,int> freq;
        while(r < n){
          int x = nums[r];
         
          count += freq[x]++;
          while(count >= k){
            ans += (n-r); //range of r for every fixed value of n
            
            count -= --freq[nums[l]];
            l++;
          }
          r++;
        }
      return ans;
    }
};