class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<int> powers;
        vector<int> answer;

        long long mod = 1e9 + 7;

        for (int i = 0; i < 32; i++) {

            if (n & 1) {

                powers.push_back(1LL << i);
            }
            n = (n >> 1);
        }

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];
            long long pdt = powers[l];

            for (int j = l + 1; j <= r; j++) {

                pdt = (pdt* powers[j]) % mod;
            }

            answer.push_back(pdt);
        }

        return answer;
    }
};