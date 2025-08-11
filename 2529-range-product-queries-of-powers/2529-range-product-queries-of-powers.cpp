class Solution {
public:
    long long mod = 1e9 + 7;

    void buildSegmentTree(vector<long long>& segmentTree, vector<long long>& powers, int i,
                          int l, int r) {

        if (l == r) {
            segmentTree[i] = powers[l];
            return;
        }

        int mid = l + (r - l) / 2;
        // left
        buildSegmentTree(segmentTree, powers, 2 * i + 1, l, mid);

        // right
        buildSegmentTree(segmentTree, powers, 2 * i + 2, mid + 1, r);

        segmentTree[i] =
            (segmentTree[2 * i + 1] * segmentTree[2 * i + 2]) % mod;
    }

    long long productQueriesSegment(int start, int end,
                                    vector<long long>& segmentTree, int i, int l,
                                    int r) {

        // out of bound

        if (r < start || l > end) {
            return 1;
        }

        // complete inside

        else if (start <= l && r <= end) {
            return segmentTree[i];
        }

        // overlapping

        int mid = l + (r - l) / 2;
        // left
        return (productQueriesSegment(start, end, segmentTree, 2 * i + 1, l, mid) *
                productQueriesSegment(start, end, segmentTree, 2 * i + 2, mid + 1,
                               r)) %
               mod;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<long long> powers;
        vector<int> answer;

        for (int i = 0; i < 32; i++) {

            if (n & 1) {

                powers.push_back(1LL << i);
            }
            n = (n >> 1);
        }

        int s = powers.size();
        vector<long long> segmentTree(4 * s);

        buildSegmentTree(segmentTree, powers, 0, 0, s - 1);

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            long long pdt =
                productQueriesSegment(l, r, segmentTree, 0, 0, s - 1);

            answer.push_back(pdt);
        }

        return answer;
    }
};