class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> freq1(26), freq2(26);

        for(auto & ch : s1){

            freq1[ ch - 'a'] ++;

        }

        int n = s1.size();
        int m = s2.size();

        int i = 0;
        int j = 0;

        while(j < m){


            freq2[s2[j] - 'a']++;

            if(j-i+1 > n){ // shrink

            freq2[s2[i] - 'a']--;
            i++;

            }

            if(j-i+1 == n && freq1 == freq2){
                return true;
                
            }


            j++;                   


        }

        return false;
        
    }
};