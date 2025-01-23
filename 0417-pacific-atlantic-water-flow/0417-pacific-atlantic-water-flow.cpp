class Solution {
public:
    vector<int> dx = {-1, 0, +1, 0};
    vector<int> dy = {0, -1, 0, +1};
    
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &vis, vector<vector<int>> &heights, int n, int m) {
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && heights[x][y] <= heights[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) q.push({i, 0}), pacific[i][0] = 1;
        for (int j = 0; j < m; j++) q.push({0, j}), pacific[0][j] = 1;
        bfs(q, pacific, heights, n, m);

       
        while (!q.empty()) q.pop();

        for (int i = 0; i < n; i++) q.push({i, m - 1}), atlantic[i][m - 1] = 1;
        for (int j = 0; j < m; j++) q.push({n - 1, j}), atlantic[n - 1][j] = 1;
        bfs(q, atlantic, heights, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
