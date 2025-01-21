class Solution {
public:
 vector<int> topologicalSort(vector<vector<int>> &edges, int n)  {
    unordered_map<int, vector<int>>g;
    vector<int>indegree(n,0);
    for(auto &e : edges){
        g[e[0]].push_back(e[1]); 
        indegree[e[1]]++;
    }
    queue<int>q;    
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    vector<int>topo;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        topo.push_back(cur);
        for(auto &nbr : g[cur]){
            indegree[nbr]--;
            if(indegree[nbr]==0)
                q.push(nbr);
        }
    }
    return topo;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo = topologicalSort(prerequisites,numCourses);
        if(topo.size()!=numCourses)
        return {};
        reverse(topo.begin(),topo.end());
        return topo;
    }
};