class Solution {

    // down and right
    int[][] dir = { { 1, 0 }, { 0, 1 } };

    public boolean dfs(char[][] grid, int i, int j, int count, boolean [][][] visited) {

        if(grid[i][j] == '('){
            count++;
        }else if(grid[i][j] == ')'){
            count--;
        }

        if(count < 0){
            return false;
        }

        int remainingSteps = (grid.length - 1 - i) + (grid[0].length - 1 - j);

        if(count > remainingSteps) return false; 

        if (i == grid.length - 1 && j == grid[0].length - 1) {
            
            return count == 0;
        }

        if(visited[i][j][count]) {
            return false;
        }

        visited[i][j][count] = true;

        for (int d = 0; d < 2; d++) {

            int in = i + dir[d][0];
            int jn = j + dir[d][1];

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


        if (grid[0][0] == ')' || grid[n-1][m-1] == '(')
            return false;

        
        if((n + m -1) %2 != 0) return false;

        int maxCount = ((n + m)/2) + 1;

        boolean[][][] visited = new boolean[n][m][maxCount];

        return dfs(grid, 0, 0, 0, visited);

    }
}