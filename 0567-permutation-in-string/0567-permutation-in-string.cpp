class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int winSize = s1.size();
        int i = 0;
        int j = s1.size() - 1;
        unordered_map<char, int> freq;
        while (j < s2.size()) {
            for (int k = i; k <= j; k++) {
                freq[s2[k]]++;
                freq[s1[k - i]]--;
            }
            bool loopcompleted = true;
            for (auto [el, count] : freq) {
                if (count != 0) {
                    i++;
                    j++;
                    freq.clear();
                    loopcompleted = false;
                    break;
                }
            }
            if (loopcompleted)
                return true;
        }
        return false;
    }
};