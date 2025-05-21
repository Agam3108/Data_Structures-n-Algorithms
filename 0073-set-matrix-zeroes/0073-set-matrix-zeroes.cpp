class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
          int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> matrix2(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix2[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<m;k++){
                        matrix2[i][k]=0;
                    }
                    for(int l=0;l<n;l++){
                        matrix2[l][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=matrix2[i][j];
            }
        }
    }
};