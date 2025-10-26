class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> rotten(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        int freshOrange = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1){
                    freshOrange++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    rotten[i][j] = true;
                }
            }
        }

        int mins = 0;

        // multi-source bfs

        while (!q.empty()) {

            int s = q.size();

            while (s--) {

                auto f = q.front();
                q.pop();

                int i = f.first;
                int j = f.second;

                for (auto d : dir) {
                    int i_ = i + d[0];
                    int j_ = j + d[1];

                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m &&
                        !rotten[i_][j_] && grid[i_][j_] == 1) {

                            q.push({i_,j_});
                            rotten[i_][j_] = true;
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