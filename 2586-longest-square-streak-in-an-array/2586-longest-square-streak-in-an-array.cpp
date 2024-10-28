class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        set<long long> st;
        st.insert(nums.begin(), nums.end());
        int maxCount = -1;
        for ( auto it : st) {
            int count = 0;
            while (st.find(it) != st.end()) {
                count++;
                it = it*it*1LL;
            }
            if (count >= 2)
                maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};