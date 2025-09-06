class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int V, vector<bool>& visited,
             vector<bool> & onStack) {

        visited[V] = true;
        onStack[V] = true;

        for (auto& v : adj[V]) {

            if ( onStack[v]) {
                return true;
                
            }


            if(!visited[v]){

                if(dfs(adj, v, visited, onStack)){
                    return true;
                }

            }
        }

         onStack[V] = false;
        return false;

        
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        vector<vector<int>> adj(numCourses);

        for (auto& link : prerequisites) {

            int u = link[1];
            int v = link[0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            if (!visited[i]) {

                if(dfs(adj, i, visited, onStack)){
                    return false;
                }
            }
        }

       

        return true;
    }
};