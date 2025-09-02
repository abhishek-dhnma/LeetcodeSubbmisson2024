class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> charFreq(26, 0);

        int i = 0;

        int maxFreq = 0;

        int n = s.length();

        for(int j=0; j<n; j++){
            charFreq[s[j] - 'A']++;

            maxFreq = max(maxFreq, charFreq[s[j] - 'A'] );


            if(j-i+1 - maxFreq > k){
                charFreq[s[i] - 'A']--;
                i++;
            }
        }

        return n - i;
        
    }
};