class Solution {
public:
    vector<vector<int>> direction = {{0,1}, {1,0}, {-1,0}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int Q = queries.size();

        vector<int> result(Q, 0);
        vector<pair<int,int>> sortedQ;
        
        for(int i = 0; i < Q; i++) {
            sortedQ.push_back({queries[i], i});
        }

        sort(sortedQ.begin(), sortedQ.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<>> qp;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int points = 0;
        qp.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        for(int i = 0; i < Q; i++) {
            int queryValue = sortedQ[i].first;
            int idx = sortedQ[i].second;
            
            while (!qp.empty() && qp.top()[0] < queryValue) {
                auto top = qp.top();
                qp.pop();

                int x = top[1], y = top[2];
                points++;

                for (auto& dir : direction) {
                    int nx = x + dir[0], ny = y + dir[1];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true; // **Fix: Assign true correctly**
                        qp.push({grid[nx][ny], nx, ny});
                    }
                }
            }

            result[idx] = points;
        }

        return result;
    }
};
