class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, n, ans);
        return ans;
    }
    void solve(int row, vector<string>& board, int n,
               vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                solve(row + 1, board, n, ans);
                board[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string>& board, int row, int col) {
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        int i = row, j = col;
        while (i >= 0 && j < board.size()) {
            if (board[i--][j++] == 'Q') {
                return false;
            }
        }
        i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i--][j--] == 'Q') {
                return false;
            }
        }
        return true;
    }
};