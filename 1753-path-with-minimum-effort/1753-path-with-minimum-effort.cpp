class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));


        result[0][0] = 0;
        pq.push({0, {0, 0}});
        

        while (!pq.empty()) {

            auto pr = pq.top();

            int d = pr.first;
            int x = pr.second.first;
            int y = pr.second.second;

            pq.pop();

            for (auto& dr : dir) {

                int x_ = x + dr[0];
                int y_ = y + dr[1];

                if (x_ >= 0 &&x_ < n && y_ >= 0 && y_ < m) {

                    int diff = max(d, abs(heights[x][y] - heights[x_][y_]));

                    if (diff < result[x_][y_]) {
                        result[x_][y_] = diff;
                        pq.push({result[x_][y_], {x_,y_}});
                    }



                }
            }
        }


        return result[n-1][m-1];
    }
};