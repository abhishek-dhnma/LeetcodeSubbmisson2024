class Solution {
public:

    void dfs(unordered_map<int, vector<int>> & adj, int V, vector<bool> & visited){

        visited[V] = true;

        for(auto & v : adj[V]){
            if(!visited[v]){ // if not visited - explore & visited
                dfs(adj, v, visited);
            }
        }

        return;

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int m = isConnected[0].size();

        unordered_map<int, vector<int>> adj;

        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(isConnected[i][j] == 1){

                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    
                }                
            }
        }


        int count  = 0;


        for(int i=0; i<n; i++){

            if(!visited[i]){
                dfs(adj, i, visited);
                count++;
            }
        }

        return count;

        
        
    }
};