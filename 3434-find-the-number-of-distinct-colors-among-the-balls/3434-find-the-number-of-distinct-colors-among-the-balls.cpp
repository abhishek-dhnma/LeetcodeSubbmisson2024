class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int nq = queries.size();

        unordered_map<int, int> balls;

        unordered_map<int, int> freq;

        vector<int> result;

        for (const auto& q : queries) {

            int b = q[0];
            int c = q[1];

            if (balls[b] != 0) {

                freq[balls[b]]--;

                if (freq[balls[b]] == 0) {
                    freq.erase(balls[b]);
                }
            }

            balls[b] = c;
            freq[c]++;

            result.push_back(freq.size());
        }

        return result;
    }
};