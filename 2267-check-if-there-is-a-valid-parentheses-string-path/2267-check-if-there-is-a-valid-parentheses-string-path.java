class Solution {

    // Allowed directions: Down and Right
    int[][] dir = { { 1, 0 }, { 0, 1 } };

    public boolean dfs(char[][] grid, int i, int j, int count, boolean[][][] visited) {

        // 1. Update the balance of brackets on the fly
        if (grid[i][j] == '(') {
            count++;
        } else if (grid[i][j] == ')') {
            count--;
        }

        // 2. PRUNING: Too many closing brackets
        if (count < 0) {
            return false;
        }

        // 3. PRUNING: Too many opening brackets
        // Calculate the exact number of steps remaining to reach the bottom-right corner.
        int remainingSteps = (grid.length - 1 - i) + (grid[0].length - 1 - j);
        
        // If we need to close more brackets than the steps we have left, it's impossible.
        if (count > remainingSteps) {
            return false;
        }

        // 4. BASE CASE: Reached the bottom-right corner
        if (i == grid.length - 1 && j == grid[0].length - 1) {
            return count == 0; // Valid if all brackets are properly closed
        }

        // 5. MEMOIZATION: Have we been at this exact state before?
        // If we visited this cell with the same 'count' and it returned false, don't re-calculate.
        if (visited[i][j][count]) {
            return false;
        }
        visited[i][j][count] = true; // Mark state as visited/failed

        // 6. EXPLORE: Move Down and Right
        for (int d = 0; d < 2; d++) {
            int in = i + dir[d][0];
            int jn = j + dir[d][1];

            // Bounds check for the next move
            if (in < grid.length && jn < grid[0].length && in >= 0 && jn >= 0) {
                if (dfs(grid, in, jn, count, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    public boolean hasValidPath(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        // PRUNING A: Must start with an open bracket and end with a closed bracket
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') {
            return false;
        }

        // PRUNING B: Every path length is exactly (n + m - 1) cells.
        // A valid parenthesis string must be even. If path length is odd, it's impossible.
        if ((n + m - 1) % 2 != 0) {
            return false;
        }

        // Maximum possible open brackets is half the path length + 1 (for array sizing)
        int maxCount = ((n + m) / 2) + 1;

        // 3D cache to store states: visited[row][col][currentBracketCount]
        boolean[][][] visited = new boolean[n][m][maxCount];

        return dfs(grid, 0, 0, 0, visited);
    }
}