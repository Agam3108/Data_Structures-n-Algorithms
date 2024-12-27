class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
 
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
                   vector<int> ans;
            for (int j = 0; j < n; j++) {
                int rmin = i - k;
                int rmax = i + k;
                int cmin = j - k;
                int cmax = j + k;
                int sum =0;
                for (int k = rmin; k <= rmax; k++) {
                   
                    for (int l = cmin; l <= cmax; l++) {
                        if (k >= 0 && k < m && l >= 0 && l < n)
                            sum += mat[k][l];
                           
                    }
                
                }
                ans.push_back(sum);
               
            }
            res.push_back(ans);
        }
        return res;
    }
};