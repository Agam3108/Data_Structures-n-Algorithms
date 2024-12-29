class Solution {
public:
    bool isStrictlyIncreasing(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] <= nums[i]) {
                return false;
            }
        }
        return true;
    }

    int MinOpsToMakeStrictlyIncreasing(vector<int> &nums) {
        if (isStrictlyIncreasing(nums))
            return 0;

        int n = nums.size();
    int minOps = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] <= nums[i - 1]) {
            int increase = nums[i - 1] - nums[i] + 1;
            minOps += increase;
            nums[i] = nums[i - 1] + 1; // Update the current element to make it strictly increasing
        }
    }

    return minOps;
    }

    int minimumOperations(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> trans(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                trans[j][i] = grid[i][j];
            }
        }

        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += MinOpsToMakeStrictlyIncreasing(trans[i]);
        }
        return sum;
    }
};
