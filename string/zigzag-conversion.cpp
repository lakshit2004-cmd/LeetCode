class Solution {
public:
    string convert(string s, int numRows) {

        int n = s.size();
        if(numRows <= 1 || numRows >= n) return s;

        string res(n, ' ');
        int pos = 0;
        int cycle = 2 * numRows - 2;

        for(int r = 0; r < numRows; r++) {

            for(int j = r; j < n; j += cycle) {

                res[pos++] = s[j];

                if(r != 0 && r != numRows - 1) {
                    int diag = j + cycle - 2*r;
                    if(diag < n)
                        res[pos++] = s[diag];
                }
            }
        }

        return res;
    }
};