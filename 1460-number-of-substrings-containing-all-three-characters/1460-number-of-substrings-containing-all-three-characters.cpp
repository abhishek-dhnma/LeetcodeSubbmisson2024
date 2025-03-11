class Solution {
public:

    int numberOfSubstrings(string s) {

        int n = s.length();

        int i = 0;
        int j = 0;
        int result = 0;

        unordered_map<char, int> freq;
        while (j < n) {
            
                
            freq[s[j]]++;

            while(freq.size() == 3){
                result += (n - j);
                
                freq[s[i]]--;
                if(freq[s[i]] == 0){
                    freq.erase(s[i]);
                }
                i++;
            }

            j++;


        }

        return result;
    }
};