class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
    
        while(k--){
          int mini = nums[0];
          for(int i=1;i<n;i++){
            if(nums[i]<mini)
            mini=nums[i];
          }
          int index =-1;
          for(int i=0;i<n;i++){
            if(nums[i]==mini){
               index=i;
               break;
            }
          }
          nums[index]=mini*multiplier;
        }
        return nums;
    }
};