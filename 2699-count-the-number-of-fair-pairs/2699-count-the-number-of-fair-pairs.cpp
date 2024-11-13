class Solution {
public:
int lowerbound(vector<int> &nums,int low,int high,int ele){
    while(low<=high){
        int mid = low+((high-low)/2);
        if(nums[mid]>=ele){
            high = mid-1;
        }
        else
        low = mid+1;
    }
    return low;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       
        long long countFp = 0;
        for(int i =0 ;i<n;i++){
            int low = lowerbound(nums,i+1,n-1,lower - nums[i]);
            int high = lowerbound(nums,i+1,n-1,upper - nums[i] +1);
           countFp += 1LL*(high-low);
        }
        return countFp;
    }
};