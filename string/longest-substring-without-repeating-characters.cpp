class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        for (int i = 0; i < 128; ++i) last[i] = -1;

        int left = 0, best = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            if (last[s[i]] >= left)
                left = last[s[i]] + 1;

            last[s[i]] = i;

            int len = i - left + 1;
            if (len > best) best = len;
        }

        return best;
    }
};