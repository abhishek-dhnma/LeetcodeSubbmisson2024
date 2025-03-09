class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        // Another way to solve this question

        int n = colors.size();
        int N = k - 1;

        int len = 1;
        int result = 0;
        int lastColor = colors[0];

        int i = 1;

        while (i < n) {

            if (colors[i] == lastColor) {
                len = 1;
                lastColor = colors[i];
                i++;
                continue;
            }

            len++;
            if (len >= k) {
                result++;
            }

            lastColor = colors[i];

            i++;
        }

        i = 0;

        while (i < N) {

            if (colors[i] == lastColor) {
                len = 1;
                lastColor = colors[i];
                i++;
                continue;
            }
            len++;
            if (len >= k) {
                result++;
            }

            lastColor = colors[i];
            i++;
        }

        return result;
    }
};