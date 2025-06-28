class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            q.push({nums[i],i});
        }
        vector<pair<int,int>> v;
        while(k--){
            auto [num,idx] = q.top();
            q.pop();
            v.push_back({idx,num});
        }
        sort(v.begin(),v.end());
        for(auto [idx,num] : v){
            ans.push_back(num);
        }
        return ans;
    }
};