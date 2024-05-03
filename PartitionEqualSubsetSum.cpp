 bool isSubsetSum(vector<int>arr, int sum){
        // code here 
     int n = arr.size();
    vector<bool> prev(sum + 1, false);
    prev[0] = true;

    for (int ind = 0; ind < n; ind++) {
        vector<bool> curr(sum + 1, false); // Reset curr to all false values
        curr[0] = true;

        for (int target = 1; target <= sum; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
       int n=nums.size();
       int TotSum=0;

       for(int i=0;i<n;i++){
        TotSum+=nums[i];
       } 
       int target=TotSum/2;
       if(TotSum%2)
       return false;
       return isSubsetSum(nums,target);
    }