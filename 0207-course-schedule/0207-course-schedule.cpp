class Solution {
public:


    bool dfs( vector<vector<int>>& adj, int  V,vector<bool>& visited,  vector<bool>& onstack){


        visited[V] = true;
        onstack[V] = true;


        for(auto & v : adj[V]){

            if(onstack[v]){
                return true;
            }


            if(!visited[v]){
                if(dfs(adj, v, visited, onstack)){
                    return true;
                }
            }

        }



        onstack[V]= false;
        return false;



    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites ) {
int n = numCourses;
        vector<vector<int>> adj(n);

        


        for(auto & cour : prerequisites){

            int u = cour[1];
            int v = cour[0];

            adj[u].push_back(v);

        }

        vector<bool> visited(n, false);
        vector<bool> onstack(n, false);


        for(int i=0; i<n; i++){

            if(!visited[i]){

                if(dfs(adj, i, visited, onstack)){
                    return false;
                }

            }


        }

        return true;
        
    }
};