class Solution {
public:
    int result = 0;

    void solve(string& s, int n, int val, char ch1, char ch2) {

        for (int i = 0; i < n - 1; i++) {

            while (s[i] == ch1 && s[i + 1] == ch2) {
                s.erase(i, 2);
                result += val;
                i = max(0, i - 2);
                n -= 2;
            }
        }
    }

    int maximumGain(string s, int x, int y) {

        char ch1, ch3;
        char ch2, ch4;

        int mx_val = max(x, y);
        int mn_val = min(x, y);

        if (x > y) {
            ch1 = 'a';
            ch2 = 'b';
        } else {
            ch1 = 'b';
            ch2 = 'a';
        }

        int n = s.size();

        solve(s, n, mx_val, ch1, ch2);

        if (ch1 == 'a' && ch2 == 'b') {
            ch1 = 'b';
            ch2 = 'a';
        } else {
            ch1 = 'a';
            ch2 = 'b';
        }

        solve(s, n, mn_val, ch1, ch2);

        return result;
    }
};