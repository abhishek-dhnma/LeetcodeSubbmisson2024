class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int s1 = word1.size();
        int s2 = word2.size();

        int i = 0;
        int j = 0;

        string ans = "";

        while(i < s1 && j < s2){
            
            ans += word1[i];
            ans += word2[j];

            i++;
            j++;

        }

        if( i < s1){
            while(i < s1){
                ans += word1[i];
                i++;
            }

        }

        if(j < s2){

            while(j < s2){
                ans += word2[j];
                j++;
            }

        }

        return ans;
        
    }
};