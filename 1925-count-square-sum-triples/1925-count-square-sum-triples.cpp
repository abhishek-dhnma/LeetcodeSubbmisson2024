class Solution {
public:
    int countTriples(int n) {
int count = 0;

        for (int c = n; c >= 1; c--) {

            int sc = c * c;

            int l = 1;
            int r = c - 1;

            while (l < r) {

                int sum = (l * l) + (r * r);

                if (sum < sc) {
                    l++;
                } else if (sum > sc) {
                    r--;
                } else if (sum == sc) {
                    count++;
                    l++;
                    r--;
                }

            }

        }

        return count * 2;
        
        
    }
};