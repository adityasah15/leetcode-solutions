class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generate(n, 0, 0, s, ans);
        return ans;
    }
    void generate(int n, int o, int c, string& s, vector<string>& ans) {
        if (o == n && c == n) {
            ans.push_back(s);
            return;
        }
        if (o > n || c > o)
            return;
        s += '(';
        generate(n, o + 1, c, s, ans);
        s.pop_back();
        s += ')';
        generate(n, o, c + 1, s, ans);
        s.pop_back();
    }
};