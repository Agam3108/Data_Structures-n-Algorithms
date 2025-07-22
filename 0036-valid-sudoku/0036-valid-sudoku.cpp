class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        unordered_set<char> rowHash[9];
        unordered_set<char> colHash[9];
        unordered_set<char> boxHash[9];

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char val = board[row][col];
                if (val == '.') continue;

                int boxIndex = (row / 3) * 3 + (col / 3);

                if (rowHash[row].count(val) || colHash[col].count(val) || boxHash[boxIndex].count(val)) {
                    return false;
                }

                rowHash[row].insert(val);
                colHash[col].insert(val);
                boxHash[boxIndex].insert(val);
            }
        }
        return true;

    }
};