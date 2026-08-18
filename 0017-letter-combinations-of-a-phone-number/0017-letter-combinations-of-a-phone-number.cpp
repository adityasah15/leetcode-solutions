class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> pad = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        vector<string> ans;
        string ds;
        solve(0, digits, ds, ans, pad);
        return ans;
    }
    void solve(int digitIdx, string& digits, string& ds, vector<string>& ans,
               const vector<string>& pad) {
        if (digitIdx == digits.size()) {
            ans.push_back(ds);
            return;
        }
        const string& letters = pad[digits[digitIdx] - '0'];
        for (char c : letters) {
            ds.push_back(c);
            solve(digitIdx + 1, digits, ds, ans, pad);
            ds.pop_back();
        }
    }
};