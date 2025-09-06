class Solution {
public:
    int n;

    void bfs(vector<vector<int>>& isConnected, int V, vector<bool>& visited) {

        queue<int> q;
        q.push(V);
         visited[V] = true;

        while (!q.empty()) {

            int f = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (!visited[v] && isConnected[f][v] == 1) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        n = isConnected.size();

        int count = 0;

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }

        return count;
    }
};