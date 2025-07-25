class Solution {
public:
    int maxSum(vector<int>& nums) {
         unordered_set<int> seen;
        vector<int> unique_nums;
        bool allNegative = true;
        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                unique_nums.push_back(num);
            }
            if(num>=0)
            allNegative = false;
        }
       sort(nums.begin(),nums.end());
       if(allNegative)
       return nums[nums.size()-1];
       int maxsum = 0;
       for(int num : unique_nums){
           if(num > 0)
           maxsum += num;
       }
        return maxsum;
    }
};