class Solution {
public:
bool BFS(int src,vector<vector<int>> &graph,vector<int> &colour){
    queue<int> q;
    q.push(src);
    colour[src] = 0;
    while(!q.empty()){
        auto int curr =q.front();
        q.pop();
        for(const auto nbr : graph[curr]){
             if(colour[nbr]==-1){
                colour[nbr] = colour[curr] ? 0 : 1;
                q.push(nbr);
             }
             else if(colour[nbr]==colour[curr])
             return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> color(n,-1);
      for(int i = 0;i<n;i++){
        if(color[i]==-1){
            if(BFS(i,graph,color)==false)
            return false;
        }
      }  
      return true;
    }
};