class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto & edge : times){

            int u = edge[0] - 1;
            int v = edge[1] - 1 ;
            int w = edge[2];

            adj[u].push_back({v,w});

        }

        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> result(n, INT_MAX);

        result[k-1] = 0;
        pq.push({0,k-1}); // (weight,node)


        while(!pq.empty()){

            auto [w, u]  = pq.top();
            pq.pop();


            for(auto & pr : adj[u] ){
                    int v = pr.first; 
                    int d = pr.second;

                    if(d > result[v]) continue;


                    if(d + w < result[v]){

                        result[v] =  d + w;
                        pq.push({result[v], v});

                    }


            }

            
        }
        
        int ans;
        for(int i=0; i<n; i++){

            
            if(result[i] == INT_MAX){
                ans = -1;
                break;
            }

            ans = max(ans, result[i]);

        }

return ans;


        
    }
};