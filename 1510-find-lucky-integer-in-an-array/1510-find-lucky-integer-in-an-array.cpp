class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            mpp[arr[i]]++;
        }
        int ans = -1 ;
        for(const auto it : mpp){
            if(it.first == it.second){
                ans = max(ans,it.first);
            }
        }
        return ans;
    }
};