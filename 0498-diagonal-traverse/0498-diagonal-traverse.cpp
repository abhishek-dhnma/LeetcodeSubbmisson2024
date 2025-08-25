class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        map<int, vector<int>> mp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int idx = i + j;

                mp[idx].push_back(mat[i][j]);
            }
        }

        for (auto& [k, v] : mp) {

            if (k % 2 == 0) {
                // even
                reverse(v.begin(), v.end());
            }

            for (auto& e : v) {
                ans.push_back(e);
            }
        }

        return ans;
    }
};