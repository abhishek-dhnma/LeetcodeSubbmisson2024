class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int completeCount = 0;

        // BFS to find all components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                unordered_set<int> componentNodes;
                int edgeCount = 0;

                q.push(i);
                visited[i] = true;
                componentNodes.insert(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node]) {
                        edgeCount++; // Count edges (will be halved later)
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                            componentNodes.insert(neighbor);
                        }
                    }
                }

                int size = componentNodes.size();
                int expectedEdges = size * (size - 1); // Each edge counted twice
                if (edgeCount == expectedEdges) {
                    completeCount++;
                }
            }
        }

        return completeCount;


        
    }
};