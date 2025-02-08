class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>> p;
        for(int i =0;i<n;i++){
            p.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(p.size() > k)
            p.pop();
        }
        vector<int> res;
        vector<vector<int>> ans;
        while(p.size()>0){
            pair<int,int> pq = p.top().second;
            p.pop();
            res.push_back(pq.first);
            res.push_back(pq.second);
            ans.push_back(res);
            res.clear();
        }
        return ans;
    }
};