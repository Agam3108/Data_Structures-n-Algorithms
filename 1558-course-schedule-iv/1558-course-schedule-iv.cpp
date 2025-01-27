class Solution {
public:
  unordered_map<int, unordered_set<int>> topologicalSort(vector<vector<int>> &edges, int n)  {
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
     unordered_map<int, unordered_set<int>> nodePrerequisites;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
       
        for(auto nbr : g[cur]){
             nodePrerequisites[nbr].insert(cur);
                for (auto prereq : nodePrerequisites[cur]) {
                    nodePrerequisites[nbr].insert(prereq);
                }
            indegree[nbr]--;
            if(indegree[nbr]==0)
                q.push(nbr);
        }
    }
    return nodePrerequisites;
}
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans;
       
        unordered_map<int, unordered_set<int>> vec = topologicalSort(prerequisites,numCourses);
        for(auto q : queries)
        ans.push_back(vec[q[1]].contains(q[0]));
        return ans;
    }
};