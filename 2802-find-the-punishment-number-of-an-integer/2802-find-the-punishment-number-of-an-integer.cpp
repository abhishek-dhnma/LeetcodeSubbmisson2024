class Solution {

public:
    bool check(int idx, int currsum, string s, int i) {

        if (idx == s.length()) {
            return currsum == i;
        }

        if (currsum > i) {
            return false;
        }

        bool possible = false;
        for (int j = idx; j < s.length(); j++) {
            string sub = s.substr(idx, j - idx + 1);
            int val = stoi(sub);

            possible = possible || check(j + 1, currsum + val, s, i);

            if (possible == true) {
                return true;
            }
        }

        return possible;
    }

    int punishmentNumber(int n) {

        int result = 0;

        for (int i = 1; i <= n; i++) {
            int sq = i * i;

            string s = to_string(sq);
            if (check(0, 0, s, i)==true) {
                result += sq;
            }
        }

        return result;
    }
};