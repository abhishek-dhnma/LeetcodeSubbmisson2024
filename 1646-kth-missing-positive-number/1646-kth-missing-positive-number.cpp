class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;

        // Binary search for first index where missing >= k
        while (l <= r) {
            int mid = l + (r - l) / 2;
            // number of missing positives before (and up to) arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // need more missing numbers -> go right
                l = mid + 1;
            } else {
                // missing >= k -> move left to find first such index
                r = mid - 1;
            }
        }

        // l is the first index with missing(l) >= k (or l == n)
        // The k-th missing positive is l + k
        return l + k;
    }
};
