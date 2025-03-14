class Solution {
public:
    bool canDis(vector<int>& candies, int mid, long long k) {
        int n = candies.size();

        for (int i = 0; i < n; i++) {
            k -= candies[i] / mid;

            if (k <= 0) {
                return true;
            }
        }

        return k <= 0;
    }


    int maximumCandies(vector<int>& candies, long long k) {

        // Optimal Soln

        auto max_e = *max_element(candies.begin(), candies.end());

        int l = 1;
        int r = max_e;
        int result = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (canDis(candies, mid, k)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};