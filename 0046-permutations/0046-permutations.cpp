class Solution {
public:
void permutations(vector<int> &arr,vector<vector<int>> &res,int idx){
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }
    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        permutations(arr,res, idx + 1);
        swap(arr[idx], arr[i]);
      }
    
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
       
        vector<vector<int>> ans;
       
        permutations(nums,ans,0);
        return ans;
    }
};