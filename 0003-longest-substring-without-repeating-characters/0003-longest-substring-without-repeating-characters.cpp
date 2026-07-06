class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_set<char> seen;
        int maxlen = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            int count = j - i + 1;
            if (!seen.count(s[j])) {
                seen.insert(s[j]);

                maxlen = max(maxlen, count);
                j++;
            } else {
                seen.erase(s[i]);
                i++;
            }
        }
        return maxlen;
    }
};