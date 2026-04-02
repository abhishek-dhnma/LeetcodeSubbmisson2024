class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();

        int maxans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> count(26, 0);
            for (int j = i; j < n; j++) {

                char curchar = s[j];

                count[curchar - 'a']++;

                int valid = true;

                for (int k = 0; k < 26; k++) {

                    if (count[k] != 0 && count[k] != count[curchar - 'a']) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    maxans = max(maxans, j - i + 1);
                }
            }
        }

        return maxans;
    }
};