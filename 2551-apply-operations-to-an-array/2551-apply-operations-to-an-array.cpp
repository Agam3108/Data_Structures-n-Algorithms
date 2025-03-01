class Solution {
public:
  void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }

    }
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int k = n-1;
        while(--k){
            for(int i = 0;i<n-1;i++){
                if(nums[i]==nums[i+1]){
                    nums[i] *= 2;
                    nums[i+1] = 0;
                }
                else continue;
            }
        }
        moveZeroes(nums);
        return nums;
    }
};