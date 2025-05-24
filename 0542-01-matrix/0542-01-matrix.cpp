class Solution {
public:

vector<int> dr = {-1,+1,0,0};
vector<int> dc = {0,0,-1,+1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0)
               { ans[i][j] = 0;
                q.push({i,j});
               }
            }
        }
      while(!q.empty()){
        int r = q.front().first ;
        int c = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || ans[nr][nc] != -1)
            continue;
                ans[nr][nc] = 1 + ans[r][c];
                q.push({nr,nc});
            
        }
      }
     return ans;
    }
};