class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0},   {-1, 0}, {0, -1},
                               {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if (n == 0 || m == 0 || grid[0][0] != 0) {
            return -1;
        }


        // BFS 

        queue<pair<int, int>> que;
        que.push({0, 0});
        grid[0][0] = 1;

        int level = 0;

        while (!que.empty()) {

            int N = que.size();

            while (N--) {

                auto cur = que.front();
                int x = cur.first;
                int y = cur.second;
                que.pop();

                if (x == n - 1 && y == n - 1) {
                    return level + 1;
                }

                for (auto& d : dir) {

                    int x_ = x + d[0];
                    int y_ = y + d[1];

                    if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n &&
                        grid[x_][y_] != 1) {

                        que.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            level++;
        }

        return -1;


    }
};