class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==0 || m==0)
        return 0;
        int count = 0;
         vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
    
                    if (rowCount[i] > 1 || colCount[j] > 1) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};