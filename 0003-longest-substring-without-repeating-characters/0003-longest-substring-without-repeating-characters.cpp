class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i = 0;
        int j = 0;

        int n = s.size();

        unordered_map<char, int> mp;

        int maxlen = 0;

        while ( j < n) {

            if (mp.find(s[j]) == mp.end()) {
                // present
                maxlen = max(maxlen, j - i + 1);
                mp[s[j]]++;
                j++;
            } else {

                mp.erase(s[i]);
                i++;
            }
        }

        return maxlen;
    }
};