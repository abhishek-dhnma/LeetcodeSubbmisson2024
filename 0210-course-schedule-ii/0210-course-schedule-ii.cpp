class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<vector<int>> adj(n);

        vector<int> inDegree(n, 0);

        for(auto & p : prerequisites){
            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
            inDegree[v]++;
        }


        // insert into queue

        queue<int> q;

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }


        // Kahn's Algorithm

        while(!q.empty()){

            int u = q.front();
            q.pop();
            ans.push_back(u);
            

            for(auto & v : adj[u]){

                inDegree[v]--;

                if(inDegree[v] == 0){
                    
                    q.push(v);
                }
            }
            
        }

        if((int) ans.size() == n){
            return ans;
        }

        return {};

        
        
    }
};