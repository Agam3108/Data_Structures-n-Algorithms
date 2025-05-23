class Solution {
public:
    vector<int> dx = {-1, 0, +1, 0};
    vector<int> dy = {0, +1, 0, -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int oc = image[sr][sc];
        image[sr][sc] = color;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;
        queue< pair<int, int>> q;
        q.push( {sr, sc});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
           
            int x = node.first;
            int y = node.second ;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if ( nx>=0 && nx<n && ny>=0 && ny < m && !vis[nx][ny] && image[nx][ny] == oc) {
                    vis[nx][ny] = 1;
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};