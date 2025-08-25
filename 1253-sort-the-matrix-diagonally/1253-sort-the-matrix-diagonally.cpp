class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        map<int, deque<int>> mp;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                int idx = i - j;

                mp[idx].push_back(mat[i][j]);
            }
        }

        for (auto& [k, v] : mp) {
            sort(v.begin(), v.end());
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                int idx = i - j;

                if (!mp[idx].empty()) {
                    mat[i][j] = mp[idx].front();
                    mp[idx].pop_front();
                }
            }
        }

        return mat;
    }
};