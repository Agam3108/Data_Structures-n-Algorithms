class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
         int lisMax = 1;
         int ldsMax = 1;
         int len = 1; int len2 = 1;
         for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1])
            len++;
            
            else{
                if(len>lisMax)
                lisMax = len;
                
                len = 1;
               
            }
         }
         for(int i = 1;i<n;i++){
            if(nums[i] < nums[i-1])
            len2++;
            else{
                if(len2 > ldsMax)
                ldsMax = len2;
                len2 = 1;
            }
         }
         if(len > lisMax)
         lisMax = len;
         if(len2 > ldsMax)
         ldsMax = len2;
        return max(lisMax,ldsMax);
    }
};