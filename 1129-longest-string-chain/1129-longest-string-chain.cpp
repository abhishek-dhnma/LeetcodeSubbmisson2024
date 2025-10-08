class Solution {
public:
    bool isPredecessor(string s1, string s2) {

        
        int i = 0;
        int j = 0;

        int n = s1.size();
        int m = s2.size();

        // if length is not s2 length is not s1 + n : false
        if ( m != n + 1) return false;


        while (i < n && j < m) {

            if (s1[i] == s2[j]) {
                i++;
            } 
            j++;
        }

    
        return i == n;
    }

    int longestStrChain(vector<string>& words) {

        int n = words.size();

        vector<int> countLIS(n, 1);

        // sorting based on length
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            return s1.length() < s2.length();
        });

        // LIS

        int maxLISResult = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (isPredecessor(words[j], words[i])) {

                    countLIS[i] = max(countLIS[i], countLIS[j] + 1);
                    maxLISResult = max(maxLISResult, countLIS[i]);
                }
            }
        }

        return maxLISResult;
    }
};