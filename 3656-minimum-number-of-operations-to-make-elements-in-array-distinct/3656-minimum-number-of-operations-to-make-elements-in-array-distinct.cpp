class Solution {
public:
bool isDistinct(vector<int> & nums){
    set<int> uniqueElements(nums.begin(), nums.end());
        return uniqueElements.size() == nums.size();
}
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        while (!isDistinct(nums) && !nums.empty()) {
            if (nums.size() >= 3) {
                nums.erase(nums.begin(), nums.begin() + 3);
            } else {
                nums.erase(nums.begin(), nums.end());
            }
            count++;
        }

        return count;
    }
};