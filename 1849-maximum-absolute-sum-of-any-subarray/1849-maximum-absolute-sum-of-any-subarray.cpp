class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minPrefixSum = INT_MAX;
        int maxPrefixSum = INT_MIN;
        int prefixSum = 0;
        int maxAbsSum = 0;
        for(int num : nums){
            prefixSum += num;
            minPrefixSum = min(prefixSum,minPrefixSum);
            maxPrefixSum = max(prefixSum,maxPrefixSum);
            if(prefixSum >= 0){
                maxAbsSum = max(maxAbsSum,max(prefixSum,prefixSum-minPrefixSum)) ;
            }
            else if(prefixSum <= 0)
            maxAbsSum = max(maxAbsSum,max(abs(prefixSum),abs(prefixSum-maxPrefixSum)));
        }
        return maxAbsSum;
    }
};