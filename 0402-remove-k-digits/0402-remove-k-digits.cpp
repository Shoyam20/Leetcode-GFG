class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        int n = num.size();
        if (k >= n)
            return "0";

        for (int i = 0; i < n; i++) {

            while (!st.empty() && k != 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while (!st.empty() && k != 0) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string s = "";

        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        while (s.size() != 0 && s.back() == '0')
            s.pop_back();
        reverse(s.begin(), s.end());

        if (s.size() == 0)
            return "0";
        return s;
    }
};