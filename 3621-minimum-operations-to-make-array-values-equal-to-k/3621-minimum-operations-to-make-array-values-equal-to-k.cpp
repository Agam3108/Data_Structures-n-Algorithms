class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int operations = 0;
     
       map<int,int> mp;
       for(int i =0;i<n;i++){
        mp[nums[i]]++;
       }
       for(int i = 0;i<n;i++){
        if(nums[i]<k)
        {
            return -1;
            break;
        }
       }
       if(mp.find(k)!=mp.end())
       return mp.size()-1;
     return mp.size();
    }
};