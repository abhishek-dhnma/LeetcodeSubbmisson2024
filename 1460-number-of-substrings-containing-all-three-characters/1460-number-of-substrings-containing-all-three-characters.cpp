class Solution {
public:

    int numberOfSubstrings(string s) {

        int n = s.length();

        int i = 0;
        int j = 0;
        int result = 0;

        int freq[3] = {0};
        while (j < n) {
            
            freq[s[j] - 'a' ] ++;

            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                result += (n - j);
                
                freq[s[i] - 'a']--;

                i++;
            }

            j++;

        }

        return result;
    }
};