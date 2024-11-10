class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        auto hasTwoAdjacentIncreasingSubarrays = [&](int k) -> bool {
            if(k == 1) return n >= 2;
            
           
            vector<int> dp(n, 1);
            
            for(int i = 1; i < n; i++) {
                if(nums[i] > nums[i-1]) {
                    dp[i] = dp[i-1] + 1;
                }
            }
          
            for(int i = k-1; i < n-k; i++) {
                if(dp[i] >= k) {  
                    int len = dp[i+k];
                    if(len >= k) return true;
                }
            }
            
            return false;
        };

        int left = 1, right = n / 2;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hasTwoAdjacentIncreasingSubarrays(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};