class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        int freq1[26] = {0};
        int freq2[26] = {0};
        int winsize = s1.size();

        for (int i = 0; i < winsize; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        int i = 0, j = winsize - 1;
        while (j < s2.size()) {
            bool same = true;
            for (int k = 0; k < 26; k++) {
                if (freq1[k] != freq2[k]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                return true;
            }
            freq2[s2[i] - 'a']--;
            i++;
            j++;
            if (j < s2.size())
                freq2[s2[j] - 'a']++;
        }
        return false;
    }
};