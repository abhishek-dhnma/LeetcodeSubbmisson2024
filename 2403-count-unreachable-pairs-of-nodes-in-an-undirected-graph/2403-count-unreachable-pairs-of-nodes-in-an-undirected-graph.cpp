class Solution {
public:

    // DSU data structures
    vector<int> parent;  // parent[i] stores the representative (root) of set i
    vector<int> rank;    // rank[i] is an approximation of tree height (used for union by rank)

    // Find with path compression
    int find(int x) {
        // If x is its own parent, it's the root
        if (x == parent[x]) {
            return x;
        }
        // Otherwise, recursively find root and compress path (make parent[x] = root)
        return parent[x] = find(parent[x]);
    }

    // Union two sets by rank
    void Union(int x, int y) {
        int x_p = find(x); // find root of x
        int y_p = find(y); // find root of y

        // If both nodes already belong to the same set → do nothing
        if (x_p == y_p) {
            return;
        }

        // Union by rank: attach smaller tree under larger tree
        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;  // x's root becomes parent
        } else if (rank[x_p] < rank[y_p]) {
            parent[x_p] = y_p;  // y's root becomes parent
        } else {
            // If ranks are equal, attach x under y and increase y's rank
            parent[x_p] = y_p;
            rank[y_p] += 1;
        }
    }

    // Main function to count unreachable pairs of nodes
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Step 1: Initialize DSU
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0); 
        // iota assigns parent[i] = i for all i (initially, each node is its own parent)

        // Step 2: Apply union operation for all edges
        // This connects nodes into components
        for (auto &edge : edges) {
            int x = edge[0];
            int y = edge[1];
            Union(x, y);
        }

        // Step 3: Count the size of each connected component
        vector<long long> cnt(n, 0); 
        for (int i = 0; i < n; i++) {
            cnt[find(i)]++; // increment size of component root(i)
        }

        // Step 4: Calculate total number of possible node pairs
        // Formula: nC2 = n * (n-1) / 2
        long long total_number_pairs = (long long)n * (n - 1) / 2;

        // Step 5: Calculate number of connected pairs
        // For each connected component of size s,
        // all nodes inside are reachable from each other (directly or indirectly).
        // Example: a -- root -- b (all nodes share the same root path in DSU).
        // So the number of connected pairs in a component of size s is:
        // sC2 = s * (s - 1) / 2
        long long connected_pairs = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > 1) { 
                connected_pairs += cnt[i] * (cnt[i] - 1) / 2;
            }
        }

        // Step 6: Unreachable pairs = total pairs - connected pairs
        return total_number_pairs - connected_pairs;
    }
};
