class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        int x = (n * n);
        vector<int> diffArray(x+1, 0);

        for (int i = 0; i < queries.size(); i++) {

            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            for(int r = r1; r<= r2; r++){
                int s = (r * n) + c1;
            int e = (r * n) + c2;

            diffArray[s] += 1;
            diffArray[e + 1] -= 1;
            }
        }

        // prefix diff array

        for (int i = 1; i <=x; i++) {
            diffArray[i] += diffArray[i - 1];
        }

        vector<vector<int>> res(n, vector<int>(n, 0));

        for (int i = 0; i < x ; i++) {

            int r = i / n;
            int c = i % n;

            res[r][c] = diffArray[i];
        }

        return res;
    }
};