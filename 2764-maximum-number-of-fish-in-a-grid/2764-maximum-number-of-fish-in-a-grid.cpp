class Solution {
public:
    vector<int> dx = {+1, 0, -1, 0};
    vector<int> dy = {0, +1, 0, -1};

    bool isValid(int x, int y, vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        return (x >= 0 && x < n && y >= 0 && y < m); // Corrected condition
    }

    int bfs(int startX, int startY, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        queue<pair<int, int>> q;
        q.push({startX, startY});
        vis[startX][startY] = 1;

        int maxSum = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;

            maxSum += grid[x][y];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny, grid) && !vis[nx][ny] && grid[nx][ny] > 0) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return maxSum;
    }

    int findMaxFish(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int totalMax = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    totalMax = max(totalMax, bfs(i, j, grid, vis));
                }
            }
        }
        return totalMax;
    }
};
