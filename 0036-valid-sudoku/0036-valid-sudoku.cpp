class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> squares[9];
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                int box = (r / 3) * 3 + (c / 3);
                int el = board[r][c];
                if (el == '.')
                    continue;
                if (rows[r].count(el) || cols[c].count(el) ||
                    squares[box].count(el)) {
                    return false;
                } else {
                    rows[r].insert(el);
                    cols[c].insert(el);
                    squares[box].insert(el);
                }
            }
        }
        return true;
    }
};