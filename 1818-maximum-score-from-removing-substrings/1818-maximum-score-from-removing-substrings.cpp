class Solution {
public:
    string removeSubstr(string s, string& matchStr) {

        int i=0; // use for writing
        int j=0; // use for reading
        int n = s.size();

        while(j<n){

            s[i] = s[j]; // writing on idx i whatever j reads
            i++;

            if( i >=2 && s[i-2] ==  matchStr[0] && s[i-1] == matchStr[1]){ 
                // found matchstr before i
                i -= 2;
            }

            j++;
        }

        s.erase(s.begin() + i, s.end());
    return s;
        
    }
    int maximumGain(string s, int x, int y) {

        int n = s.size();
        int score = 0;

        string maxStr = (x >= y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        // first pass

        string temp_first = removeSubstr(s, maxStr);
        int L = temp_first.length();

        int charRemoved = (n - L);
        score += (charRemoved / 2) * max(x, y);

        // second pass
        string temp_second = removeSubstr(temp_first, minStr);
        charRemoved = L - temp_second.length();

        score += (charRemoved / 2) * min(x, y);

        return score;
    }
};