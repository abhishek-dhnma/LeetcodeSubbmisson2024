class Solution {
public:
vector<vector<int>> direction = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q,0);

        vector<pair<int,int>> sortedQ;
        for(int i=0; i <Q; i++){
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> qp;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int points = 0;

        qp.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        for(int i=0; i<Q; i++){
            int queryValue = sortedQ[i].first;
            int idx = sortedQ[i].second;
            while(!qp.empty() && qp.top()[0] < queryValue){
                int i = qp.top()[1];
                int j = qp.top()[2];

                qp.pop();

                points++;

                for(auto& dir : direction){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ <n && !visited[i_][j_]){
                        qp.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }

                 

            }

            result[idx] = points;
        }

        return result;


    }
};