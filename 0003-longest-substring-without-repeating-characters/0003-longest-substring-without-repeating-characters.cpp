class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // set
        unordered_set<char> st;
        // string size
        int n = s.size();
        // edge case
        if (n == 0)
            return 0;

        // main logic

        int i = 0;
        int j = 0;

        int maxLen = 0;

        while (j < n) {

            if (st.find(s[j]) == st.end()) {
                // not present
                st.insert(s[j]);
                int windowSize = j - i + 1;

                maxLen = max(maxLen, windowSize);

                j++;

            } else {
                // present
                st.erase(s[i]);
                i++;
            }
        }

        return maxLen;
    }
};