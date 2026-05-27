class Solution {
public:
    void dfs(int open, int close, int n, string &curr, vector<string> &res) {

        if(curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if(open < n) {
            curr.push_back('(');
            dfs(open + 1, close, n, curr, res);
            curr.pop_back();
        }

        if(close < open) {
            curr.push_back(')');
            dfs(open, close + 1, n, curr, res);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> res;

       
        res.reserve(1 << n); 

        string curr;
        dfs(0, 0, n, curr, res);

        return res;
    }
};