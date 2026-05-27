class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> freq;
        for (auto &w : words) freq[w]++;

        for (int i = 0; i < wordLen; i++) {

            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {

                // 🔥 Use string_view instead of substr
                string_view word(&s[right], wordLen);

                if (freq.count(string(word))) {
                    window[string(word)]++;
                    count++;

                    while (window[string(word)] > freq[string(word)]) {
                        string_view leftWord(&s[left], wordLen);
                        window[string(leftWord)]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        res.push_back(left);

                        string_view leftWord(&s[left], wordLen);
                        window[string(leftWord)]--;
                        left += wordLen;
                        count--;
                    }

                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return res;
    }
};