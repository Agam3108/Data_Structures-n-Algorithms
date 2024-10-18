class Solution {
public:
int maximumBitwiseOR(vector<int> &nums){
   int n = nums.size();
    int maximumBitwiseOr = 0; 
    for (int i = 0; i < n; i++) {
        int val = 0; 
        for (int j = i; j < n; j++) {
            val |= nums[j];
            maximumBitwiseOr = max(maximumBitwiseOr, val); 
        }
    }
    return maximumBitwiseOr;
}

    int countMaxOrSubsets(vector<int>& nums) {
       int n = nums.size();
    int maxOr = maximumBitwiseOR(nums); 
    int count = 0;
    function<void(int, int)> findSubsets = [&](int i, int currentOr) {
        if (i == n) {
            if (currentOr == maxOr) count++;
            return;
        }
        findSubsets(i + 1, currentOr | nums[i]);
        findSubsets(i + 1, currentOr);
    };
    findSubsets(0, 0);
    return count;
    }
};