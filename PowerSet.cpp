vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets=1<<n;
        vector<vector<int>> ans;
        for(int num=0;num<subsets;num++){
            vector<int> ls;
            for(int i=0;i<n;i++){
                if(num & (1<<i))
                ls.push_back(nums[i]);
            }
            ans.push_back(ls);
        }
        return ans;
    }