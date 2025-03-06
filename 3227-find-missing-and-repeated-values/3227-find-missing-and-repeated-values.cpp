class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> counts(n * n + 1, 0);
        long long actual_sum = 0;

        int repeated = 0;

     for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                counts[val]++;
                actual_sum += val;
                if (counts[val] == 2) {
                    repeated = val;
                }
            }
        }

        long long expected_sum =  (long long )(n * n) * (n * n+1) /2;
        int missing = expected_sum - actual_sum + repeated;

        return {repeated, missing};

        
    }
};