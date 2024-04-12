int BinarySubArrayWithSum(vector<int>& nums,int k){
int l=0,r=0,sum=0,count=0;
while(r<nums.size()){
    sum+=(nums[r]%2);
    while(sum>k){
        sum=sum-(nums[l]%2);
        l++;
    }
    count=count+(r-l+1);
    r++;
}
return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
       int ans=(BinarySubArrayWithSum(nums,k)-BinarySubArrayWithSum(nums,k-1));
        return ans;
    }