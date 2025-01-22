class Solution {
    private:
    vector<int> dx = {-1,0,+1,0};
    vector<int> dy = {0,+1,0,-1};
public:

bool isValid(int x,int y,vector<vector<int>> & grid){
    int n = grid.size();
    int m = grid[0].size();
    if(x >=0 && x<n && y>=0 && y<m)
    return true;
    return false;
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> heights(n,vector<int>(m,n+m));
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isWater[i][j]==1)
                heights[i][j] = 0;
                else{
                    if(i>0)
                    heights[i][j] = min(heights[i][j],heights[i-1][j]+1);
                    if(j>0)
                    heights[i][j] = min(heights[i][j],heights[i][j-1]+1);
                }
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(i<n-1)
                    heights[i][j] = min(heights[i][j],heights[i+1][j]+1) ;
                    if(j<m-1)
                    heights[i][j] = min(heights[i][j],heights[i][j+1]+1);              
                    
            }
        }
        return heights;
    }
};