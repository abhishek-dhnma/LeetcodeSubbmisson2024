class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int m = grid.size();      // number of rows
        int n = grid[0].size();   // number of columns

        // Initialize boundaries for the smallest rectangle
        int maxCol = 0;
        int minCol = n;   // start with max possible col
        int maxRow = 0;
        int minRow = m;   // start with max possible row

        // Traverse the grid
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) { // found a cell with value 1

                    // Update column boundaries
                    maxCol = max(maxCol, c);
                    minCol = min(minCol, c);

                    // Update row boundaries
                    maxRow = max(maxRow, r);
                    minRow = min(minRow, r);
                }
            }
        }

        // Rectangle area covering all 1s:
        // (width)  = maxCol - minCol + 1
        // (height) = maxRow - minRow + 1
        return (maxCol - minCol + 1) * (maxRow - minRow + 1);
    }
};
