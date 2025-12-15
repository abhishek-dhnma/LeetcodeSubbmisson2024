class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        long long ans = 0;

        int n = prices.size();
        if (n == 1)
            return 1;

        int i = 0;
        int j = 0;

        while (j < n) {

            if (j + 1 < n && prices[j] - prices[j + 1] != 1) {

                int winlen = j - i + 1;

                ans += (winlen * (long long) 1 * (winlen + 1) / 2);

                j++;
                i = j;
                continue;
            }

            j++;

            if (j == n) {
                int winlen = j - i;

                ans += ((winlen) * (long long)1 * (winlen + 1) / 2);
            }
        }

        return ans;
    }
};