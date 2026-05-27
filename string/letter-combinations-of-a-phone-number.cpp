class Solution {
public:
    void dfs(int i, string &digits, string &curr, vector<string> &res, string map[]) {

        if(i == digits.size()) {
            res.push_back(curr);
            return;
        }

        const string &letters = map[digits[i] - '0'];

        for(char c : letters) {
            curr.push_back(c);
            dfs(i + 1, digits, curr, res, map);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        static string map[] = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> res;

        // 🔥 pre-allocate max possible size (improves runtime)
        int maxSize = 1;
        for(char d : digits)
            maxSize *= map[d - '0'].size();
        res.reserve(maxSize);

        string curr;
        dfs(0, digits, curr, res, map);

        return res;
    }
};