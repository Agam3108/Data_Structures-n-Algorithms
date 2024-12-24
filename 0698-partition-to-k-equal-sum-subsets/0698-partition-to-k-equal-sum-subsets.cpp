class Solution {
public:
bool backtrack(int i,int k,int subsetSum,int target, vector<int> &nums, vector<bool> &vis){
       if (k == 0) return true; 
        if (subsetSum == target) // If a subset is completed, move to the next subset
            return backtrack(0, k - 1, 0, target, nums, vis);

        for (int j = i; j < nums.size(); j++) {
            if (vis[j] || subsetSum + nums[j] > target) continue; 

            vis[j] = true; 
            if (backtrack(j + 1, k, subsetSum + nums[j], target, nums, vis))
                return true;
            vis[j] = false;
            if (subsetSum == 0) break;
        }
        return false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
         int sum = accumulate(nums.begin(),nums.end(),0);
           int target = sum / k;
        vector<bool> vis(nums.size(), false);
        if(sum%k!=0)
        return false;
        return backtrack(0,k,0,target,nums,vis);
    }
};