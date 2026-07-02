class Solution {

    // 4 possible directions: Right, Down, Up, Left
    int[][] dir = new int[][]{
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    // DFS to visit all connected land cells
    public void dfs(char[][] grid, int i, int j, boolean[][] visited) {

        int n = grid.length;
        int m = grid[0].length;

        // Mark current cell as visited
        visited[i][j] = true;

        // Explore all 4 directions
        for (int[] d : dir) {

            int newi = i + d[0];
            int newj = j + d[1];

            // 1. Boundary Check
            if (newi < 0 || newi >= n || newj < 0 || newj >= m) {
                continue;
            }

            // 2. Skip already visited cells
            if (visited[newi][newj]) {
                continue;
            }

            // 3. Skip water cells
            if (grid[newi][newj] == '0') {
                continue;
            }

            // Visit neighbouring land
            dfs(grid, newi, newj, visited);
        }
    }

    public int numIslands(char[][] grid) {

        int n = grid.length;
        int m = grid[0].length;

        // Keeps track of visited cells
        boolean[][] visited = new boolean[n][m];

        int numberOfIsland = 0;

        // Traverse every cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Found an unvisited land cell
                // This means we discovered a new island
                if (grid[i][j] == '1' && !visited[i][j]) {

                    // Mark the complete connected component
                    dfs(grid, i, j, visited);

                    // Increase island count
                    numberOfIsland++;
                }
            }
        }

        return numberOfIsland;
    }
}