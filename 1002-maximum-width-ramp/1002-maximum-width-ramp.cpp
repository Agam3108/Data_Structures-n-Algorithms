class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            if (nums[i] != nums[j])
                return nums[i] < nums[j];  
            return i < j;  
        });
        
        int minIndex = indices[0];
        int maxWidth = 0;
        
        for (int i = 1; i < n; ++i) {
            int index = indices[i];
            
            maxWidth = max(maxWidth, index - minIndex);
            
            minIndex = min(minIndex, index);
        }
        
        return maxWidth;
    }
};
