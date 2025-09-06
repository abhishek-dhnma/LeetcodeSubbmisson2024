class Solution {
public:

    void bfs(vector< vector<int>> & adj, int V, vector<bool> & visited){


        queue<int> q;
        q.push(V);

        while(!q.empty()){

            int f = q.front();
            q.pop();


            for(auto & v : adj[f]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }

        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector< vector<int>> adj(n);


        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(isConnected[i][j]){
adj[i].push_back(j);
                adj[j].push_back(i);

                }
                
            }
        }


        int count = 0;

        vector<bool> visited(n , 0);


        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(adj, i, visited);
                count++;
            }
        }


        return count;
        
    }
};