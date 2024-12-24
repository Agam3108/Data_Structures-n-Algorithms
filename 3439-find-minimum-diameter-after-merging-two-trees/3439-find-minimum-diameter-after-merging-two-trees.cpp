class Solution {
public:
vector<vector<int>> adjLs1 ;
        vector<vector<int>> adjLs2 ;
vector<vector<int>> buildAdjList(vector<vector<int>>& edges,int size) {
        vector<vector<int>> adjList(size);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }
int findDiameter(int N,vector<vector<int>> &adjLs){
   auto [farthestNode, _] = findFarthestNode(N, adjLs, 0);

        auto [_, diameter] = findFarthestNode(N, adjLs, farthestNode);
        return diameter;
}
pair<int,int> findFarthestNode(int n,vector<vector<int>> & adjLs,int src){
    queue<int> q;
    vector<bool> vis(n,false);
    q.push(src);
    vis[src] = 1;
    int maxdist = 0; int farthestNode = src;
    while(!q.empty()){
       int size = q.size();
       for(int i =0;i<size;i++){
        int currNode = q.front();
        q.pop();
        farthestNode = currNode;
        for(int neighbour : adjLs[currNode]) {
            if(!vis[neighbour]){
                vis[neighbour] = true;
                q.push(neighbour);
            }
        }
       }
       if(!q.empty())
       maxdist++;
        
    }
    return {farthestNode,maxdist};

}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        adjLs1= buildAdjList(edges1,n);
       adjLs2 =  buildAdjList(edges2,m);
        int d1 = findDiameter(n,adjLs1);
        int d2 = findDiameter(m,adjLs2);
        int d = ceil(d1/2.0) + ceil(d2/2.0) + 1;
        return max(d,max(d1,d2));
    }
};