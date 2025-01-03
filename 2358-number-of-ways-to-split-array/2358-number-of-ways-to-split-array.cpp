class Solution {
public:

    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
       vector<long long int> prefixSum(n-1);
       vector<long long int> suffixSum(n-1);
       long long int sum = 0;
       long long int sum1 = 0;
       for(int i =0;i<n-1;i++){
        sum += nums[i];
        sum1 += nums[n-i-1];
        prefixSum[i] = sum;
        suffixSum[i] = sum1;
       }
       reverse(suffixSum.begin(),suffixSum.end());
       for(int i = 0;i<n-1;i++){
        if(prefixSum[i] >= suffixSum[i])
        count++;
       }
       return count;
    }
};