class Solution {
public:
int delRow[4] ={-1,0,+1,0};
int delCol[4] = {0,+1,0,-1};
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long ans = 0;
             long long sum = 0;
             int countNeg = 0;
             int minAbs = INT_MAX;
        for(int i = 0;i<n;i++){
          
            for(int j = 0;j<n;j++){
              sum += abs(matrix[i][j]);
              minAbs = min(minAbs,abs(matrix[i][j]));
              if(matrix[i][j]<0){
                 countNeg++;
              }
            
            }
        }
        if(countNeg%2==0)
        ans = sum;
        else
        ans = sum - 2*minAbs;
     return ans;
    }
};