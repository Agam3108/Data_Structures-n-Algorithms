class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        int row = mat.size();
        int col = mat[0].size();
        vector<int> rc(row,0);
        vector<int> cc(col,0);
        unordered_map<int,pair<int,int>> mpp;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                int val = mat[i][j];
                mpp[val] = {i,j};
            }
        }
        for(int i =0;i<n;i++){
           int num = arr[i];
           auto [x,y] = mpp[num];
           rc[x]++;
           cc[y]++;
           if(rc[x]==col || cc[y]==row)
           return i;
        }
     return -1;
    }
};