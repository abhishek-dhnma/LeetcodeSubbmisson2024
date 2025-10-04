class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        map<char, vector<int>> mp;

        for (int i = 0; i < m; i++) {

            mp[t[i]].push_back(i);
        }

        int prev = -1;

        for (int i = 0; i < n; i++) {

            char ch = s[i];

            if (mp.find(ch) == mp.end()) {

                return false;
            }

            vector<int> idxs = mp[ch];

            auto it = upper_bound(idxs.begin(), idxs.end(), prev);

            if (it == idxs.end()) {
                return false;
            }

            prev = *it;
        }

        return true;
    }
};