class Solution {
public:
    bool isValid(string s) {

        string st;
        st.reserve(s.size()); // 🔥 avoid resizing

        for(char c : s) {

            if(c == '(') st.push_back(')');
            else if(c == '{') st.push_back('}');
            else if(c == '[') st.push_back(']');
            else {
                if(st.empty() || st.back() != c)
                    return false;
                st.pop_back();
            }
        }

        return st.empty();
    }
};
