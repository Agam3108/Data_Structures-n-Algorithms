class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
       int n = cost.size();
       vector<int> res;
       res.push_back(cost[0]);
       for(int i = 1;i<n;i++){
          res.push_back(min(res[i-1],cost[i]));
       } 
       return res;
    }
};