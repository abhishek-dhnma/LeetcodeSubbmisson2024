class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        vector<int> vec(100);
        int ans = 0;

        for (auto& d : dominoes) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }

            int key = d[0] * 10 + d[1];

            ans += vec[key];
            vec[key]++;
        }

        return ans;
    }
};