class Solution {

    int find(int x, vector<int>& parent) {

        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x], parent); // path compression
    }

    void Union(int x, int y, vector<int>& parent, vector<int> & rank) {

        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[y_parent] < rank[x_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] == rank[x_parent]) {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;


        for(auto & edge : connections){

            int x = edge[0]; 
            int y = edge[1];


          int x_p =  find(x, parent);
          int y_p =  find(y, parent);

          if(x_p == y_p){
            continue;
          }else{

            Union(x_p, y_p, parent, rank);
            components--;



          }

        

        }

        return components-1;
    }
};