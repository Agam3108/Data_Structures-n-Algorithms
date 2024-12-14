class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long count = 0;
        map<int,int> freq;
        while(r<n){
           freq[nums[r]]++;
           while(freq.rbegin()->first - freq.begin()->first > 2){
            freq[nums[l]]--;
            if(freq[nums[l]]==0)
            freq.erase(nums[l]);
            l++;
           }
           count += r-l+1;
           r++;
        }
        return count;
    }
};