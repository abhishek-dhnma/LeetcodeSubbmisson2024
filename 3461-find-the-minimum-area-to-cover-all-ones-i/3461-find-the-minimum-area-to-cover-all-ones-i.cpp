class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int maxCol = 0;
        int minCol = n;

        int maxRow = 0;
        int minRow = m;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) {
                    maxCol = max(maxCol, c);
                    minCol = min(minCol, c);

                    maxRow = max(maxRow, r);
                    minRow = min(minRow, r);
                }
            }
        }

        return (maxCol - minCol + 1) * (maxRow - minRow + 1);
    }
};