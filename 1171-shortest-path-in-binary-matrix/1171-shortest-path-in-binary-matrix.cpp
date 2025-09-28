class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    vector<vector<int>> direction = {{0, 1}, {1, 0},  {-1, 0}, {0, -1},
                               {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if (n == 0 || m == 0 || grid[0][0] != 0) {
            return -1;
        }

        // dijkstra algo

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));

        // min heap
        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {

            auto pr = pq.top();
            

            int d = pr.first;
            int x = pr.second.first;
            int y = pr.second.second;
            pq.pop();


            for(auto & dir : direction){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1;


                if(x_ >= 0 && x_ <n && y_ >= 0 && y_<n && grid[x_][y_] == 0){


                    if(d + dist< result[x_][y_]){
                        
                    pq.push( {d + dist , {x_,y_}});
                    grid[x_][y_] = 1;
                    result[x_][y_] = d + dist;


                    }
                    
                }
            }


        }

        if(result[n-1][n-1] == INT_MAX){
            return -1;
        }

        return result[n - 1][n - 1] + 1;
    }
};