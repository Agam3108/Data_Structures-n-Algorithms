class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mpp;
        for(int num : nums){
            mpp[num]++;
        }
        int ans;
        for(const auto it : mpp){
            if(it.second==1)
            ans = it.first;
        }
        return ans;
    }
};