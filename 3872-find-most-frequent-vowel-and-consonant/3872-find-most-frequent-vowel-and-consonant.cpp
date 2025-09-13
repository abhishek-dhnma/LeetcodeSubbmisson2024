class Solution {
public:
    int maxFreqSum(string s) {

        vector<int> freq(26, 0);

        for(auto & ch : s){
            freq[ch - 'a']++;
        }

        int v = 0;
        int c = 0;


        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){

                v = max(v, freq[s[i] - 'a']);

            }else{
                c = max(c, freq[s[i] - 'a']);
            }


        }
        

        return c + v;
    }
};