class Solution {
    // down and right
    int[][] dir = { { 1, 0 }, { 0, 1 } };

    public boolean dfs(char[][] grid, int i, int j, int count, boolean[][][] visited) {

        if (grid[i][j] == '(') {
            count++;
        } else if (grid[i][j] == ')') {
            count--;
        }

        // Pruning 1: Too many closing brackets
        if (count < 0) {
            return false;
        }

        // Pruning 2 (THE FIX): Too many open brackets. 
        // If we have more open brackets than remaining steps, we can never close them.
        // This also strictly guarantees 'count' never exceeds our 'visited' array size.
        int remainingSteps = (grid.length - 1 - i) + (grid[0].length - 1 - j);
        if (count > remainingSteps) {
            return false;
        }

        // Reached the end
        if (i == grid.length - 1 && j == grid[0].length - 1) {
            return count == 0;
        }

        // Check Cache
        if (visited[i][j][count]) {
            return false;
        }
        visited[i][j][count] = true;

        // Explore children
        for (int d = 0; d < 2; d++) {
            int in = i + dir[d][0];
            int jn = j + dir[d][1];

            if (in < grid.length && jn < grid[0].length) {
                if (dfs(grid, in, jn, count, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    public boolean hasValidPath(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // A valid path must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        // PRO TIP: Every path from top-left to bottom-right takes exactly (m + n - 1) steps.
        // A valid parenthesis string MUST have an even length.
        // If the path length is odd, it's mathematically impossible.
        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        // Max possible open brackets at any valid point is half the total path length
        int maxCount = (m + n) / 2 + 1;
        
        // Notice we don't need +1 on m and n anymore since we check bounds before entering dfs
        boolean[][][] visited = new boolean[m][n][maxCount];

        return dfs(grid, 0, 0, 0, visited);
    }
}