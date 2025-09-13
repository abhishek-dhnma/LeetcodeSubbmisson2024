class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<int, int> freq;

        for(auto & ch : s){
            freq[ch]++;
        }

        int v = 0;
        int c = 0;


        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){

                v = max(v, freq[s[i]]);

            }else{
                c = max(c, freq[s[i]]);
            }


        }
        

        return c + v;
    }
};