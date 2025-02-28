class Solution {
public:

    int lenLongestFibSubseq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]] = i;
        }
        int maxLen = 0;
        for(int i = 0;i<n;i++){
           for(int j = i+1;j<n;j++){
            int prev1 = nums[j];
            int prev2 = nums[i];
            int len = 2;
            while(mp.find(prev1+prev2)!=mp.end()) {
            len++;
            maxLen = max(maxLen,len);
            int x = prev1;
            prev1 = prev1+prev2;
            prev2 = x;
           }
          }  
        }
        return maxLen;
    }
};