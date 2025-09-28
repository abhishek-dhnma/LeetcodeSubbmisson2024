class Solution {
public:
    // Alias for priority_queue element: {distance, {x, y}}
    typedef pair<int, pair<int, int>> p;

    // 8 possible directions (horizontal, vertical, diagonal)
    vector<vector<int>> direction = {
        {0, 1}, {1, 0},  {-1, 0}, {0, -1},   // up, down, left, right
        {1, 1}, {-1, 1}, {1, -1}, {-1, -1}   // diagonals
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Edge case: invalid grid or starting cell is blocked
        if (n == 0 || m == 0 || grid[0][0] != 0) {
            return -1;
        }

        // Distance matrix -> stores shortest distance from (0,0) to each cell
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));

        // Min-heap priority queue: {distance, {x, y}}
        priority_queue<p, vector<p>, greater<p>> pq;

        // Start at (0,0) with distance = 0
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            auto pr = pq.top();
            pq.pop();

            int d = pr.first;        // Current distance
            int x = pr.second.first; // Current row
            int y = pr.second.second;// Current col

            // Explore all 8 directions
            for (auto& dir : direction) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1; // Each step costs 1

                // Check boundaries and if next cell is open (0 = free)
                if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n &&
                    grid[x_][y_] == 0) {

                    // If a shorter path to (x_, y_) is found
                    if (d + dist < result[x_][y_]) {
                        result[x_][y_] = d + dist;          // update shortest dist
                        pq.push({d + dist, {x_, y_}});      // push into heap
                        grid[x_][y_] = 1;                   // mark as visited
                    }
                }
            }
        }

        // If bottom-right cell was never reached, return -1
        if (result[n - 1][n - 1] == INT_MAX) {
            return -1;
        }

        // +1 because distance starts from 0 at (0,0), but path length counts cells
        return result[n - 1][n - 1] + 1;
    }
};
