class Solution {
public:
    void combination2(vector<vector<int>>& res, vector<int>& combination,
                      vector<int>& candidates, int target, int index) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i];
             ++i) {
            if (i == index || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combination2(res, combination, candidates,
                             target - candidates[i], i + 1);
                combination.pop_back();
            }
        }
        }
        vector<vector<int>> combinationSum2(vector<int> & candidates,
                                            int target) {
            int n = candidates.size();
            sort(candidates.begin(), candidates.end());
           // vector<vector<int>> dp(1000, vector<int>(1000 + 1));
            vector<int> ds;
            vector<vector<int>> temp;
            combination2(temp,ds,candidates,target,0);
            // for (auto it : ds) {
            //     cout << it << " ";
            // }

            // for (auto it : ans) {
            //     temp.push_back(it);
            // }
            return temp;
        }
    };