class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        int i = 0;
        int j = 0;

        // iterate and check if match ot not
        while (i < n && j < m) {
            // match condition
            if (s[i] == t[j]) {
                i++;
            }

            j++;
        }

        if (i == n) {

            return true;
        }

        return false;
    }
};