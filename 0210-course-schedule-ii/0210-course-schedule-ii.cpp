class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int V, vector<bool>& visited,
             stack<int>& st, vector<bool> & onStack) {

        visited[V] = true;
        onStack[V] = true;

        for (auto& v : adj[V]) {

            if(onStack[v]){
                return true;
            }

            if (!visited[v]) {
                if(dfs(adj, v, visited, st, onStack)){

                    return true;

                }
            }
        }

        st.push(V);

        onStack[V] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto& link : prerequisites) {

            int u = link[1];
            int v = link[0];

            adj[u].push_back(v);
        }

        stack<int> st;

        vector<int> ans;

        vector<bool> visited(numCourses, false);

        bool status  = false;

        vector<bool>  onStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if(dfs(adj, i, visited, st, onStack)){

                    status = true;
                    break;

                }
            }
        }

        if(status){
            return {};
        }

        while (!st.empty()) {

            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};