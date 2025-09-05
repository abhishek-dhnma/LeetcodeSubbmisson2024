class Solution {
public:

int n;

    void dfs(vector<vector<int>> & isConnected, int u, vector<bool> & visited){

        visited[u] = true;

        for(int v=0; v<n; v++){
            if(!visited[v] && isConnected[u][v]){ // if not visited - explore & visited
                dfs(isConnected, v, visited);
            }
        }

        return;

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

         n = isConnected.size();

        vector<bool> visited(n, false);

        int count  = 0;

        for(int i=0; i<n; i++){

            if(!visited[i]){ 
                dfs(isConnected, i, visited);
                count++;
            }
        }

        return count;

        
        
    }
};