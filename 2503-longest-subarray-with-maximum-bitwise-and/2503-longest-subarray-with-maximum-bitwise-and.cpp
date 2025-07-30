class Solution {
public:
  int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = *max_element(nums.begin(),nums.end());
        int count = 1,maxi =1;
        for(int i =0;i<n-1;i++){
            if(nums[i]==k && nums[i]==nums[i+1])
            count++;
            else
            count = 1;
               maxi = max(maxi,count);
        }
     
        return maxi;
    }
};