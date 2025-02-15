class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        if(st.find(target)==st.end())
        return false;
        return true;
    }
};