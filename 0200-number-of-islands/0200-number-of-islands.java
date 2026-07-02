class Solution {


    int[][] dir = new int[][]{{0,1}, {1,0}, {-1,0}, {0,-1}};

    public void dfs(char[][] grid, int i, int j, boolean[][] visited){
        
        
        int n = grid.length;
        int m = grid[0].length;


        visited[i][j] = true;

        for(int[] d : dir){

            int newi = i + d[0]; 
            int newj = j + d[1];

            // boundary check
            if(newi < 0 || newi >=n || newj < 0 || newj >= m){
                continue;
            }

            //already visited
            if(visited[newi][newj]) continue;


            // invalid call
            if(grid[newi][newj] == '0') continue;



            dfs(grid, newi, newj, visited);

        }

    }


    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] visited =  new boolean[n][m];

        int numberOfIsland = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    numberOfIsland++;
                }
            }
        }

        return numberOfIsland;
        
    }
}
