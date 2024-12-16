class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int minprod = 1;
        int maxprod = 1;
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            if(nums[i]<0)
            swap(maxprod,minprod);
            maxprod = max(nums[i],maxprod*nums[i]);
            minprod = min(nums[i],minprod*nums[i]);
            ans = max(ans,maxprod);

        }
        return ans;
    }
};