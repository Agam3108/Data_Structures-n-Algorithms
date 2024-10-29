class Solution {
public:
int bfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j){
     int n = grid.size();
        int m = grid[0].size();
       
        queue<pair<int, pair<int, int>>> q;  
         visited[i][j] = true;
        int dr[] = {-1, 0, +1};
    
        int dc[] = {+1,+1,+1};
        int maxMoves = 0;
        q.push({0,{i,j}});
        while(!q.empty()){
           auto node = q.front();
            q.pop();
            int moves = node.first;
            int r = node.second.first;
            int c = node.second.second;

            maxMoves = max(maxMoves, moves);
            for(int i = 0;i<3;i++){
                int nr = r+dr[i];
                int nc = dc[i] +c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>grid[r][c] && !visited[nr][nc]){
                     q.push({moves+1,{nr,nc}});
                     visited[nr][nc] = true;
                }
            }
        }
      return maxMoves;
}
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,bfs(grid,vis,i,0));
        }
        return ans;
    }
};