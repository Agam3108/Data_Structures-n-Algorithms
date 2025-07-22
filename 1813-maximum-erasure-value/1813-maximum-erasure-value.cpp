class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        unordered_set<int> st;
        int maxsubarraysum = 0;
        int sum = 0;

        while (r < n) {
            while (st.count(nums[r]) != 0) {
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            
            st.insert(nums[r]);
            sum += nums[r];
            maxsubarraysum = max(sum, maxsubarraysum);
            r++;
        }
        
        return maxsubarraysum;
    }
};