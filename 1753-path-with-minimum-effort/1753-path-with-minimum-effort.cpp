class Solution {
public:
    // Custom type: (effort_so_far, (x, y))
    typedef pair<int, pair<int, int>> P;

    // Possible 4 directions (up, down, left, right)
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        // Min-heap priority queue -> (effort, coordinates)
        // Always expand the path with the smallest current effort
        priority_queue<P, vector<P>, greater<P>> pq;

        // result[x][y] = minimum effort needed to reach (x, y)
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));

        // Starting point: effort = 0 at (0,0)
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        
        // Dijkstra’s Algorithm loop
        while (!pq.empty()) {
            auto pr = pq.top();
            pq.pop();

            int d = pr.first;           // Current effort
            int x = pr.second.first;    // Current row
            int y = pr.second.second;   // Current col

            // If we reached destination, we can return immediately
            if (x == n - 1 && y == m - 1) return d;

            // Explore all 4 directions
            for (auto& dr : dir) {
                int x_ = x + dr[0];
                int y_ = y + dr[1];

                // Check valid boundaries
                if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m) {

                    // The effort is determined by the *maximum* height difference
                    // encountered so far in this path
                    int diff = max(d, abs(heights[x][y] - heights[x_][y_]));

                    // If we found a path with smaller effort to reach (x_, y_)
                    if (diff < result[x_][y_]) {
                        result[x_][y_] = diff;
                        pq.push({diff, {x_, y_}});
                    }
                }
            }
        }

        // The destination cell’s value is our answer
        return result[n-1][m-1];
    }
};
