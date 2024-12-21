class Solution {
public:
int ans = 0;
vector<vector<int>> adj;
bitset<30001> vis=0;

void build_adj(int n,vector<vector<int>> & edges,vector<int> & val){
    for(const auto e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
long long dfs(int src,vector<int> & values,int k){
    vis[src] = 1;
    long long sum = values[src];
    for(int j: adj[src]){
       if(!vis[j]){
        sum += dfs(j,values,k);
        
       }
       sum %= k;
    }
   if(sum%k == 0)
   ans++;
   return sum;
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        build_adj(n,edges,values);
        dfs(0,values,k);
        return ans;

    }
};