class Solution {
public:
    

    void solve(int node, vector<int> adj[], vector<int> &visited){
        visited[node] = 1;
        for(auto &it: adj[node]){
            if(!visited[it]){
                solve(it, adj, visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        vector<int> adjLS[n];
        
        for (int i = 0; i < m; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjLS[u].push_back(v);
            //adjLS[v].push_back(u);
        }
        vector<int> vis(n,0);
        solve( k, adjLS, vis);
        bool sus = true;
        for(int i =0 ;i<n;i++){
            if(!vis[i]){
                for(auto it: adjLS[i]){
                    if(vis[it])
                    sus = false;
                }
            }
        }
        vector<int> rem;
        if(sus){
            for(int i =0;i<n;i++){
                if(!vis[i])
                rem.push_back(i);
            }
        }
        else{
            for(int i = 0;i<n;i++){
                rem.push_back(i);
            }
        }
        return rem;
    }
};
