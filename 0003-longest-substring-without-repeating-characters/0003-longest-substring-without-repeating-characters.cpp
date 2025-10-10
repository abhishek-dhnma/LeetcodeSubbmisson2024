class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i = 0;
        int j = 0;

        int n = s.size();

        unordered_map<char, int> mp; // freqs

        int maxlen = 0;

        // sliding window

        while(j<n){

            // conditions
            if( mp.find(s[j]) == mp.end()){
                // not present

            maxlen = max(maxlen, j - i + 1 );
            // inserting
            mp[s[j]]++;
            j++;

            }else {
                // present 
                mp.erase(s[i]);
                i++;
                // shrinking
            }


        }


        return maxlen;
        
    }
};