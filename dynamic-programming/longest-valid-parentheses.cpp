class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, left + right);
            else if (right > left)
                left = right = 0;
        }

        left = right = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, left + right);
            else if (left > right)
                left = right = 0;
        }

        return ans;
    }
};