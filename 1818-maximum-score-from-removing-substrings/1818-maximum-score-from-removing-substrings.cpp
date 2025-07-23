class Solution {
public:
    string removeSubstr(string s, string& matchStr) {
        stack<char> st;

        for (char& ch : s) {
            if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
    int maximumGain(string s, int x, int y) {

        int n = s.size();
        int score = 0;

        string maxStr = (x >= y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        // first pass

        string temp_first = removeSubstr(s, maxStr);
        int L = temp_first.length();

        int charRemoved = (n - L);
        score += (charRemoved / 2) * max(x, y);

        // second pass
        string temp_second = removeSubstr(temp_first, minStr);
        charRemoved = L - temp_second.length();

        score += (charRemoved / 2) * min(x, y);

        return score;
    }
};