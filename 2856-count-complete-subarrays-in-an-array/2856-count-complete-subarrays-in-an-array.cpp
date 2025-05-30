class Solution {
public:
int DistinctSubarray(vector<int>& nums,int k){
    int l=0,r=0,count=0;
    map<int,int> mpp;
    while(r<nums.size()){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)
            mpp.erase(nums[l]);
            l++;
        }
        count+=(r-l+1);
        r++;
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int ans=DistinctSubarray(nums,k)-DistinctSubarray(nums,k-1);
       return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int k = st.size();
        return subarraysWithKDistinct(nums,k);
    }
};