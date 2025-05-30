class Solution {
public:
vector<int> dx = {-1,-1,-1,0,+1,+1,+1,0};
vector<int> dy = {-1,0,+1,+1,+1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && grid[0][0]==0)
        return 1;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        q.push({{0,0},1});
        vis[0][0] = 0;
        if(grid[0][0]==1)
        return -1;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int len = node.second;
            for(int i = 0;i<8;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if( nr>=0 && nr < n && nc >=0 && nc<m && len + 1 < vis[nr][nc] && grid[nr][nc]==0){
                  vis[nr][nc] = len+1;
                  if(nr == n-1 && nc == m-1)
                  return len+1;
                  q.push({{nr,nc},len+1});                   
                }
            }

        }
        return -1;
    }
};