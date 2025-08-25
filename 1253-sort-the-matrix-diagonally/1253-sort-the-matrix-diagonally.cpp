class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // Handle empty matrix case
        if (mat.empty() || mat[0].empty()) return mat;

        int r = mat.size();
        int c = mat[0].size();
        // Use unordered_map with vector for efficient access and sorting
        unordered_map<int, vector<int>> mp;

        // Step 1: Group elements by anti-diagonal index (i - j)
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // Step 2: Sort each diagonal's elements in ascending order
        for (auto& [k, v] : mp) {
            sort(v.begin(), v.end());
        }

        // Step 3: Reassign sorted elements back to the matrix
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int idx = i - j;
                mat[i][j] = mp[idx].front(); // Assign first element
                mp[idx].erase(mp[idx].begin()); // Remove used element
            }
        }

        return mat;
    }
};

