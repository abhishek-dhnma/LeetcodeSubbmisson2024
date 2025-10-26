class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> rottenQueue;
        int freshCount = 0;

        // Step 1: Count fresh oranges and push all rotten ones
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    freshCount++;
                } else if (grid[r][c] == 2) {
                    rottenQueue.push({r, c});
                }
            }
        }

        if (freshCount == 0) return 0;

        int minutesPassed = 0;

        // Step 2: Multi-source BFS
        while (!rottenQueue.empty()) {
            int levelSize = rottenQueue.size();

            while (levelSize--) {
                auto [row, col] = rottenQueue.front();
                rottenQueue.pop();

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < rows &&
                        newCol >= 0 && newCol < cols &&
                        grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2; // rot it
                        freshCount--;
                        rottenQueue.push({newRow, newCol});
                    }
                }
            }

            minutesPassed++;
        }

        // Step 3: Return result
        if (freshCount == 0) {
            return minutesPassed == 0 ? 0 : minutesPassed - 1;
        }

        return -1;
    }
};
