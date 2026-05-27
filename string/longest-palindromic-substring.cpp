class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int m = 2*n + 1;

        string t(m, '#');
        for(int i = 0; i < n; i++)
            t[2*i + 1] = s[i];

        vector<int> p(m, 0);

        int center = 0, right = 0;
        int bestCenter = 0, bestLen = 0;

        for(int i = 0; i < m; i++) {
            int mirror = 2*center - i;

            if(i < right)
                p[i] = min(right - i, p[mirror]);

            while(i - p[i] - 1 >= 0 && i + p[i] + 1 < m &&
                  t[i - p[i] - 1] == t[i + p[i] + 1])
                p[i]++;

            if(i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if(p[i] > bestLen) {
                bestLen = p[i];
                bestCenter = i;
            }
        }

        int start = (bestCenter - bestLen) / 2;
        return s.substr(start, bestLen);
    }
};