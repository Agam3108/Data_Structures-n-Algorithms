class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector <vector <int>> ans;
        for(int i=0;i<n;i++){
       if(ans.empty()||intervals[i][0]>ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        }
        return ans;
    }
    static bool cmp(const std::vector<int>& a, const std::vector<int>& b){
       return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans = merge(intervals);
        return ans;
    }
};