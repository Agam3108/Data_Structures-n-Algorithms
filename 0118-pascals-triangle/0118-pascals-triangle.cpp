class Solution {
public:
vector<int> generateRows(int row){
    vector<int> res;
    long ans = 1;
    res.push_back(1);
    for(int col = 1;col<row;col++){
        ans = ans * (row - col);
        ans /= col;
        res.push_back(ans);
    }
    return res;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i = 1;i<=numRows;i++){
            pascal.push_back(generateRows(i));
        }
        return pascal;
    }
};