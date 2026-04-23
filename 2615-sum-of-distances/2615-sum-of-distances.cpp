class Solution {
public:
    using ll = long long;

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n);

        unordered_map<int, vector<int>> mp;

        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for (auto &it : mp) {
            vector<int>& pos = it.second;
            int k = pos.size();

            vector<ll> prefix(k + 1, 0);

            for (int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + pos[i];
            }

            for (int j = 0; j < k; j++) {
                ll left = (ll)pos[j] * j - prefix[j];
                ll right = (prefix[k] - prefix[j + 1]) - (ll)pos[j] * (k - j - 1);

                ans[pos[j]] = left + right;
            }
        }

        return ans;
    }
};