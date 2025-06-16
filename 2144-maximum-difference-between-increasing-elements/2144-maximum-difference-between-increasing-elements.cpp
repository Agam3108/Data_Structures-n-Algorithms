class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int n = nums.size();
    if (n < 2) return -1; 

    int maxdiff = -1;
    int minval = nums[0]; 
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] > minval) {
            int diff = nums[i] - minval;
            maxdiff = max(maxdiff, diff);
        } else {
            minval = nums[i];
        }
    }
    return maxdiff;
    }
};