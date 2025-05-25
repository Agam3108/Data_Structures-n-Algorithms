class Solution {
public:
vector<int> dr = {-1,+1,0,0};
vector<int> dc = {0,0,+1,-1};
void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &board){
  vis[r][c] = 1;
  int m = board.size();
  int n = board[0].size();
  for(int i =0;i<4;i++){
    int nr = r + dr[i];
    int nc = c + dc[i];
    if(nr>=0 && nr <m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
        dfs(nr,nc,vis,board);
      
    }
  }
}
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i =0;i<n;i++){
           if(!vis[0][i] && board[0][i]=='O'){
              dfs(0,i,vis,board);
           }
           if(!vis[m-1][i] && board[m-1][i]=='O' ){
            dfs(m-1,i,vis,board);
           }
        }
        for(int i =0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,vis,board);
            }
        }
        for(int i = 0;i<m;i++){
            for(int j =  0;j<n;j++){
                if( board[i][j]=='O' && !vis[i][j] ){
                    board[i][j] = 'X';
                   
                }
            }
        }
    }
};