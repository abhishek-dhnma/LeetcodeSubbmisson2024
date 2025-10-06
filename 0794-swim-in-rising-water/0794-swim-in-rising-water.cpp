class Solution {
public:
    // binary search - minimum to maximize
    int n;

    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool possibleToReach(int i, int j, int time, vector<vector<int>>& grid,
                         vector<vector<bool>> & visited) {

        if (i >= n || i < 0 || j < 0 || j >= n ||
            visited[i][j] == true || grid[i][j] > time) {
            return false;
        }

        visited[i][j] = true;

        if (i == n - 1 && j == n - 1) {
            return true;
        }

        for (auto& d : dirs) {

            int i_ = i + d[0];
            int j_ = j + d[1];

            if (possibleToReach(i_, j_, time, grid, visited)) {
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {

        n = grid.size();

        int l = grid[0][0];
        int r = n * n - 1;
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (possibleToReach(0, 0, mid, grid, visited)) {
                result = mid;
                r = mid - 1;
            } else {

                l = mid + 1;
            }
        }

        return result;
    }
};