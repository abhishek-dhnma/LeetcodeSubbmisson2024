class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int freshOrange = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1){
                    freshOrange++;
                }
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if(freshOrange == 0){
            return 0;
        }

        int mins = 0;

        // multi-source bfs

        while (!q.empty()) {

            int N = q.size();

            while (N--) {

                auto cell = q.front();
                q.pop();

                int i = cell.first;
                int j = cell.second;

                for (auto d : dir) {
                    int i_ = i + d[0];
                    int j_ = j + d[1];

                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m &&
                        grid[i_][j_] == 1) {

                            q.push({i_,j_});
                            grid[i_][j_] = 2;
                            freshOrange--;

                    }
                }
            }

            mins++;
        }


        if (freshOrange == 0) {
            return mins==0 ? mins : mins-1;
        }

        return -1;
    }
};