class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        int prefixSum = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
           prefixSum += nums[i];
           if(prefixSum == k)
           count++;
           int remove = prefixSum - k;
           if(mpp.find(remove)!=mpp.end())
           count += mpp[remove];
           mpp[prefixSum]++;

        }
        return count;
    }
};