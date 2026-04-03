class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;

        vector<vector<int>> adj(n);

        for(auto p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
        }


        vector<int> indeg(n);

        for(auto u : adj){
            for(auto v : u){
                indeg[v]++;
            }
        }


        queue<int> que;

        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                que.push(i);
            }
        }

        vector<int> list;


        while(!que.empty()){

            auto u = que.front();
            que.pop();
            list.push_back(u);
            for(auto v : adj[u]){

                indeg[v]--;

                if(indeg[v] == 0){
                    que.push(v);
                }

            }

        }

        return list.size() == n ;




    }
};