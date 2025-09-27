class Solution {

    vector<int> parent;
        vector<int> rank;

    int find(int x) {

        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]); // path compression
    }

    void Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

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
        if (connections.size() < n - 1) {
            return -1;
        }

        parent.resize(n);
        rank.assign(n,0);

        iota(parent.begin(), parent.end(), 0);

        

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for (auto& edge : connections) {

            if (find(edge[0]) != find(edge[1])) {
                Union(edge[0], edge[1]);
                components--;
            }
        }

        return components - 1;
    }
};