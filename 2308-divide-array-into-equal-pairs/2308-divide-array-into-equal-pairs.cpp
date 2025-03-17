class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(const auto it : mpp){
            if(it.second %2 == 1)
            return false;
        }
        return true;
    }
};