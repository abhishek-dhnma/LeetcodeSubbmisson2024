class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int nq = queries.size();

        unordered_map<int, int> balls;

        unordered_map<int, int> freq;

        unordered_set<int> s;

        vector<int> result;

        for (const auto& q : queries) {

            int b = q[0];
            int c = q[1];

            if (balls[b] != 0) {

                freq[balls[b]]--;

                if (freq[balls[b]] == 0) {
                    s.erase(balls[b]);
                    freq.erase(balls[b]);
                }
            }

            balls[b] = c;
            freq[c]++;

            s.insert(c);

            result.push_back(s.size());
        }

        return result;
    }
};