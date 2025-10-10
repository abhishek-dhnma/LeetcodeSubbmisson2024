class Solution {
public:
    bool checkInclusion(string s1, string s2) {


        // template

        // pointers
        int i = 0;
        int j = 0;

        // sizes
        int n = s1.size();
        int m = s2.size();


        // freqs

        vector<int> s1freq(26), s2freq(26);


        /// fill s1freq

        for(int i=0; i<n; i++){
            s1freq[s1[i] - 'a']++;
        }


        while( j < m){


            s2freq[ s2[j] - 'a']++;


             //shrinking

            if( j - i +1 > n){

                s2freq[s2[i] - 'a']--;
                i++; // writing
            }


            // neeed to 2 condition check

            if( j - i + 1 == n && s1freq == s2freq){
                return true;
            }

        

            j++; // read next character


        }
// at the end you wil return false

        return false;
        
    }
};