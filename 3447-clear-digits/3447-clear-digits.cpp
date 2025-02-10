class Solution {
public:
    string clearDigits(string s) {

        int n = s.size();

        if (n == 1)
            return s;

        for (int i = 1; i < n; i++) {

            if (isdigit(s[i])) {
                    s.erase(i - 1, 2);
                    i = 0;
                    n = n - 2;
            }
        }
        return s;
    }
};