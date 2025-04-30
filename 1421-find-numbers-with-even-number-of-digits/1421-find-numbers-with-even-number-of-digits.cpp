class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for (auto it : nums) {

            if (to_string(it).size() % 2 == 0) {
                ans++;
            }
        }

        return ans;
    }
};