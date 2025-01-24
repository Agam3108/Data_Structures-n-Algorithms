class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return {}; 

        vector<vector<int>> reverseGraph(n);
        vector<int> outdegree(n, 0);
        queue<int> q;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            for (int v : graph[i]) {
                reverseGraph[v].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                outdegree[neighbor]--;
                if (outdegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(res.begin(), res.end()); 
        return res;
    }
};