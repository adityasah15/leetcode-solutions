class Solution {
public:
    bool helper(string& s, int low, int high) {
        if (low >= high)
            return true;
        if (!isalnum(s[low]))
            return helper(s, low + 1, high);
        if (!isalnum(s[high]))
            return helper(s, low, high - 1);
        if (tolower(s[low]) != tolower(s[high]))
            return false;
        return helper(s, low + 1, high - 1);
    }
    bool isPalindrome(string s) { return helper(s, 0, s.size() - 1); }
};