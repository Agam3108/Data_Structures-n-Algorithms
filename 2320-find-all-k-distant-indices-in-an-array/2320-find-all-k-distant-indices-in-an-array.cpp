class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIndex ;
        for(int i = 0;i<n;i++){
            if(nums[i]==key){
                keyIndex.push_back(i);
            }
        }
        vector<int> ans;
           unordered_set<int> st;
        for(int i = 0;i<keyIndex.size();i++){
            int ind = keyIndex[i];
         
            for(int j = 0;j<n;j++){
                if(abs(j-ind)<=k && st.find(j)==st.end())
                {
                    st.insert(j);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};