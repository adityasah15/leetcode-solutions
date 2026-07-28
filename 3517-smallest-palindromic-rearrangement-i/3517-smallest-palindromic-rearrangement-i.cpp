class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string left = "";
        char middle = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                middle = 'a' + i;
            }
            left.append(count[i] / 2, 'a' + i);
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (middle != 0) {
            return left + middle + right;
        }
        return left + right;
    }
};