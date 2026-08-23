class Solution {
public:
    unordered_set<char> rows[9], cols[9], boxes[9];
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char el = board[r][c];
                int n = (r / 3) * 3 + (c / 3);
                if (el != '.') {
                    rows[r].insert(el);
                    cols[c].insert(el);
                    boxes[n].insert(el);
                }
            }
        }
        solve(0, 0, board);
    }
    bool solve(int r, int c, vector<vector<char>>& board) {
        if (r == 9)
            return true;
        if (c == 9) {
            return solve(r + 1, 0, board);
        }
        if (board[r][c] != '.') {
            return solve(r, c + 1, board);
        }
        for (int i = 1; i <= 9; i++) {
            int n = (r / 3) * 3 + (c / 3);
            char el = '0' + i;
            if (rows[r].count(el) || cols[c].count(el) || boxes[n].count(el)) {
                continue;
            }
            rows[r].insert(el);
            cols[c].insert(el);
            boxes[n].insert(el);

            board[r][c] = el;
            if (solve(r, c + 1, board) == true) {
                return true;
            }
            board[r][c] = '.';

            rows[r].erase(el);
            cols[c].erase(el);
            boxes[n].erase(el);
        }
        return false;
    }
};