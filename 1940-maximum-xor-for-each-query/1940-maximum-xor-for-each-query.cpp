class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans;
        int maximumXor = pow(2,maximumBit) - 1;
        int bxor = 0;
         for (int num : nums) {
            bxor ^= num;
        }
         for (int i = n - 1; i >= 0; i--) {
            ans.push_back(maximumXor ^ bxor);
            bxor ^= nums[i];
        }
         return ans;
    }
};