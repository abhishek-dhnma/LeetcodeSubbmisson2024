class Solution {
public:
    typedef pair<int, pair<int, int>> PP;

    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int trapRainWater(vector<vector<int>>& heightMap) {

        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> boundarycells;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int row = 0; row < n; row++) {
            for (int col : {0, m - 1}) {
                boundarycells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        for (int col = 0; col < m; col++) {
            for (int row : {0, n - 1}) {
                boundarycells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        while (!boundarycells.empty()) {

            PP tp = boundarycells.top();
            boundarycells.pop();

            int height = tp.first;
            int i = tp.second.first;
            int j = tp.second.second;

            for (auto& dir : direction) {

                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m &&
                    !visited[i_][j_]) {

                    water += max(height - heightMap[i_][j_], 0);
                    boundarycells.push(
                        {max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};