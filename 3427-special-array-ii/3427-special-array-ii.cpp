class Solution {
public:
bool bs(int start,int end,vector<int> & index){
    int lo = 0;
    int hi = index.size()-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int ind = index[mid];
        if(ind<start){
            lo = mid+1;
        }
        else if(ind>end){
            hi = mid-1;
        }
        else{
            return true;
        }
    }
    return false;
}
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<bool> ans;
        ans.resize(m);
        vector<int> index;
        for(int i = 1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2)
            index.push_back(i);
        }
        for(int i = 0;i<m;i++){
            int start = queries[i][0];
            int end = queries[i][1];
            bool isSpecial = bs(start+1,end,index);
            if(isSpecial)
            ans[i] = false;
            else
            ans[i] = true;
         
       }
       return ans;
    }
};