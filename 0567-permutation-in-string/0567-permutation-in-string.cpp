class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        int i = 0, j = s1.size() - 1;
        while (j < s2.size()) {
            bool same = true;
            for (int p = 0; p < 26; p++) {
                if (freq1[p] != freq2[p]) {
                    same = false;
                    break;
                }
            }
            if (same)
                return true;
            freq2[s2[i] - 'a']--;
            i++;
            j++;
            if (j < s2.size()) {
                freq2[s2[j] - 'a']++;
            }
        }
        return false;
    }
};