class Solution {
public:
int isPossible(vector<int>& nums, int threshold){
   int n = nums.size();
   int ind = 0;
   int c = 0;
   while(ind <=n-2){
      if(nums[ind+1]-nums[ind] <= threshold){
        c++;
        ind++;
      }
      ind++;
   }
   return c;
}
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lo = 0;
        int hi = nums[n-1]-nums[0];
        int ans = 0;
        while(lo <= hi){
           int mid = (lo + (hi-lo)/2);
           if(isPossible(nums,mid)>=p){
             ans = mid;
             hi = mid-1 ;
           }
           else{
            lo = mid+1;
           }
        }
        return ans;
    }
};