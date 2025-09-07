class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> ans;
        

        for (int i = 1; i <=n; i+=2) {

            if (i + 1 <= n) {

                ans.push_back(i);
                ans.push_back(-i);

            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};