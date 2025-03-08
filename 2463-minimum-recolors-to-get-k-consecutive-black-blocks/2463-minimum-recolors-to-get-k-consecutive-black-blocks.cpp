class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int t = 0;
            int b = 0;

            for (int j = i; j < n; j++) {

                if (blocks[j] == 'W') {
                    t++;
                }
                b++;

                if (b == k) {
                    ans = min(t, ans);
                    break;
                }
            }
            if (t == 0) {
                cout << "i " << i << " break";
                break;
            }
        }

        return ans;
    }
};