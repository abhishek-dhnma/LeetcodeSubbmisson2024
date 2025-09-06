class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited,
             vector<int>& order, vector<bool> & onStack) {

        visited[u] = true;
        onStack[u] = true;

        for (auto& v : adj[u]) {

            if(onStack[v]){
                return true;
            }

            if (!visited[v]) {
                if(dfs(adj, v, visited, order, onStack)){

                    return true;

                }
            }
        }

        

        onStack[u] = false;
        order.push_back(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {

            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
        }

        vector<int> order;

        vector<bool> visited(numCourses, false);

        vector<bool>  onStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if(dfs(adj, i, visited, order, onStack)){

                    return{};

                }
            }
        }


        reverse(order.begin(), order.end());

        return order;
    }
};