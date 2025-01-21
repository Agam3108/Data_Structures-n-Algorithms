class Solution {
public:
    vector<int> dx = {0, +1};
    vector<int> dy = {+1, 0};

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        int c = grid[0].size();
        int r = grid.size();
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x1, int y1, int x2, int y2, int& maxSum, int sum) {
        if (x1 == x2 && y1 == y2) {
            maxSum = max(maxSum, sum);
            return;
        }
        vis[x1][y1] = 1;
        for (int i = 0; i < 2; i++) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            if (isValid(nx, ny, grid) && vis[nx][ny] == 0) {
                sum += grid[nx][ny];
                dfs(grid, vis, nx, ny, x2, y2, maxSum, sum);
                sum -= grid[nx][ny];
            }
        }
        vis[x1][y1] = 0;
    }

    long long gridGame(vector<vector<int>>& grid) {
         int n = grid[0].size();
        
        vector<long long> topPrefix(n, 0), bottomPrefix(n, 0);
        topPrefix[0] = grid[0][0];
        bottomPrefix[0] = grid[1][0];
        
        for (int j = 1; j < n; ++j) {
            topPrefix[j] = topPrefix[j - 1] + grid[0][j];
            bottomPrefix[j] = bottomPrefix[j - 1] + grid[1][j];
        }
        
        long long minPointsForRobot2 = LLONG_MAX;
        
        for (int j = 0; j < n; ++j) {
            long long pointsAbove = (j + 1 < n) ? topPrefix[n - 1] - topPrefix[j] : 0;
            long long pointsBelow = (j > 0) ? bottomPrefix[j - 1] : 0;
            
            long long robot2Points = max(pointsAbove, pointsBelow);
            minPointsForRobot2 = min(minPointsForRobot2, robot2Points);
        }
        
        return minPointsForRobot2;
    }
};
