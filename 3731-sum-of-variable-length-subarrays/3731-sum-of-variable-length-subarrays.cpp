class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i =0;i<n;i++){
            int start = max(0,i-nums[i]);
            int sum = 0;
            for(int j = start;j<=i;j++){
                sum += nums[j];
            }
            totalSum += sum;
        }
        return totalSum;
    }
};