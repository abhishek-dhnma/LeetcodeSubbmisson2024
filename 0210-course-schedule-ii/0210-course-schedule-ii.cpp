class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<vector<int>> adj(n);

        for(auto & p : prerequisites){
            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
        }


        // indegree 
        vector<int> inDegree(n, 0);

        for(auto & list : adj){

            for(auto & l : list){

                inDegree[l]++;
            }

        }

        // insert into queue

        queue<int> q;

        vector<int> ans;

        int count =0 ;

        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                ans.push_back(i);
                count++;
                q.push(i);
            }
        }


        // Kahn's Algorithm

        while(!q.empty()){

            int u = q.front();
            q.pop();
            

            for(auto & v : adj[u]){

                inDegree[v]--;

                if(inDegree[v] == 0){
                    ans.push_back(v);
                    count++;
                    
                    q.push(v);
                }
            }
            
        }

        if(count == n){
            return ans;
        }

        return {};

        
        
    }
};