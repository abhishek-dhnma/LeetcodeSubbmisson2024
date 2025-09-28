class Solution {
public:
    // All 8 possible directions (horizontal, vertical, and diagonal)
    vector<vector<int>> dir = {
        {0, 1},  {1, 0},   {-1, 0}, {0, -1},   // 4 directions (up, down, left, right)
        {1, 1},  {-1, -1}, {1, -1}, {-1, 1}    // 4 diagonals
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If grid is empty or starting cell is blocked, no path exists
        if (n == 0 || m == 0 || grid[0][0] != 0) {
            return -1;
        }

        // BFS queue -> each element is a coordinate (x, y)
        queue<pair<int, int>> que;
        que.push({0, 0});

        // Mark the starting cell as visited by setting it to 1
        grid[0][0] = 1;

        int level = 0; // "level" in BFS = steps taken so far

        while (!que.empty()) {
            int N = que.size(); // Number of nodes at current BFS level

            while (N--) {
                auto cur = que.front();
                int x = cur.first;
                int y = cur.second;
                que.pop();

                // If we reached the bottom-right cell, return path length
                if (x == n - 1 && y == n - 1) {
                    return level + 1;  // +1 since we count steps starting at (0,0)
                }

                // Explore all 8 directions
                for (auto& d : dir) {
                    int x_ = x + d[0];
                    int y_ = y + d[1];

                    // Check boundaries and if the next cell is not blocked
                    if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n &&
                        grid[x_][y_] == 0) {

                        que.push({x_, y_});
                        grid[x_][y_] = 1; // mark visited
                    }
                }
            }
            level++; // increment distance after finishing current BFS level
        }

        // If queue is empty and target was never reached, no path exists
        return -1;
    }
};
