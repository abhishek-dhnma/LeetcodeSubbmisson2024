class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();

        int ans = INT_MAX;

        for (int i = 0; i <= n-k; i++) {
            int t = 0;

            for (int j = i; j-i+1 <= k; j++) {

                if (blocks[j] == 'W') {
                    t++;
                }

                
            }
            ans = min(t, ans);

        }

        return ans;
    }
};