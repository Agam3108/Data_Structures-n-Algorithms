class Solution {
public:
bool zero(vector<int> &arr){
    unordered_set<int> st;
    for(int i = 0;i<arr.size();i++){
        st.insert(arr[i]);
    }
    for(const auto it : st){
        if(it!=0)
        return false;
    }
    return true;
}
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums.size();
        vector<int> diffArray(n+1);
        int prefixSum = 0;
        for(int i = 0;i<m;i++){
            int start = queries[i][0];
            int end = queries[i][1];
            diffArray[start] += 1;
            diffArray[end+1] -= 1;
            
        }
        for (int numIndex = 0; numIndex < n; numIndex++) {
            prefixSum += diffArray[numIndex];
            if (prefixSum < nums[numIndex]) return false;
        }
        
      return true;
    }
};