class Solution {
public:
    unordered_set<int> columns, diag, anti;
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return ans;
    }
    void solve(int row, vector<string>& board) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (columns.count(col) || diag.count(row + col) ||
                anti.count(row - col)) {
                continue;
            }
            columns.insert(col);
            diag.insert(row + col);
            anti.insert(row - col);

            board[row][col] = 'Q';
            solve(row + 1, board);
            board[row][col] = '.';

            columns.erase(col);
            diag.erase(row + col);
            anti.erase(row - col);
        }
    }
};