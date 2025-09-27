class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){

        if(x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){

        int x_p = find(x); 
        int y_p = find(y);

        if(x_p == y_p) {
            return;
        }


        if(rank[x_p] > rank[y_p]){

            parent[y_p] = x_p;


        }else if(rank[x_p] < rank[y_p]){
            parent[x_p] = y_p;


        }else if(rank[x_p] == rank[y_p]){
                parent[x_p] = y_p;
                rank[y_p] +=1;
        }



    }


    long long countPairs(int n, vector<vector<int>>& edges) {

      

        parent.resize(n);
        rank.assign(n,0);
        iota(parent.begin(), parent.end(), 0);

        for(auto & egde : edges){
            int x = egde[0];
            int y = egde[1];
            Union(x, y);
        }


        //find sizes of each component

        vector<long long> cnt(n,0);
        for(int i=0; i<n; i++){
            cnt[find(i)]++;
        }


        long long total_number = (long long)n * (n - 1) / 2 ;

        long long connected_pairs = 0;

        for (int i = 0; i < n; ++i) {
            if (cnt[i] > 1) {
                connected_pairs += cnt[i] * (cnt[i] - 1) / 2;
            }
        }



        return total_number -connected_pairs  ;
        
    }
};