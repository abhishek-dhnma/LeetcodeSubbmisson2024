class Solution {
public:
    vector < vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    typedef pair<int, pair<int,int>> P;

    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;


        minTime[0][0] = 0;
        pq.push({0, {0,0}});

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;


        while (!pq.empty()) {
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            
            int i = cell.first;
            int j = cell.second;


            pq.pop();

            if(i == n-1 && j == m-1){
                return currTime;
            }

            
            for (auto &d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
                    int waitTime = max(moveTime[ni][nj] - currTime, 0);

                    int arrivalTime = waitTime + currTime + 1; // 1 for moving 1 cell --> 2 cell

                    if(minTime[ni][nj] > arrivalTime){
                        minTime[ni][nj] = arrivalTime;
                        pq.push({arrivalTime, {ni, nj}});
                    }
                }
                
            }
        }

        return -1;
    }
};