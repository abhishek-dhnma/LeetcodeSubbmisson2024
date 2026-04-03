class Solution {
public:

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        for(auto& e : edges){
            int v = e[0];
            int u = e[1];

            adj[u].push_back(v);
        }


        vector<int> indeg(n, 0);
        for(auto u : adj){
            for(auto v : u){
                indeg[v]++;
            }
        }

        // kahn's algorithm


        queue<int> que;

        for(int i =0; i<n; i++){
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

        
        if(list.size() == n){
            return list;
        }

        return {};

        
        
    }
};