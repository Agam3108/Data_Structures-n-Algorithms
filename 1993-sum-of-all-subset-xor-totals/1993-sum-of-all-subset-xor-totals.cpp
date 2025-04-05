class Solution {
public:
void f(vector<int>& nums,int ind,int n,vector<vector<int>>& ans,vector<int>& res){
    if(ind >= n){
        ans.push_back(res);
        return ;
    }
    res.push_back(nums[ind]);
    f(nums,ind+1,n,ans,res);
    res.pop_back();
    f(nums,ind+1,n,ans,res);
}
vector<vector<int>> findAllSubsets(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> res;
    f(nums,0,n,ans,res);
    return ans;
}
int findXOR(vector<int>& res){
    int bxor = 0;
    for(const auto it : res){
        bxor ^= it;
    }
    return bxor;
}
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets = findAllSubsets(nums);
        int m = subsets.size();
        int sum = 0;
        for(int j = 0;j<m;j++){
            vector<int> res = subsets[j];
            if(res.size()==0)
            continue;
            sum += findXOR(res);
        }
        return sum;
    }
};