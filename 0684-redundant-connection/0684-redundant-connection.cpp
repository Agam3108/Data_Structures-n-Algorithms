class Solution {
public:
int findUPar(vector<int> & parent,int x){
    if(parent[x]==x)
    return x;
    return parent[x] = findUPar(parent,parent[x]);
}
bool Union(vector<int> & parent,int u ,int v,vector<int> & size ){
    int pu = findUPar(parent,u);
    int pv = findUPar(parent,v);
    if(pu == pv)
    return true;
    if(size[pu] >= size[pv])
    {
        size[pu] += size[pv];
        parent[pv] = pu ;
    }
    else{
        size[pv] += size[pu];
        parent[pu] = pv;
    }
    return false;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> size(n+1,1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
        for(int i = 0;i<n;i++){
            if(Union(parent,edges[i][0],edges[i][1],size))
            return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};