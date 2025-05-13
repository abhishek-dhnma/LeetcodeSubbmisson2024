class Solution {
public:
     const int mod = 1000000007;
    int lengthAfterTransformations(string s, int t) {

        //unordered_map<char, int> mp;

        vector<int> mp(26,0);

        for(auto & ch : s){
            mp[ch-'a']++;
        }

        while(t--){
            //unordered_map<char, int> temp;
            vector<int> temp(26,0);

            for(int i=0; i<26; i++){
                char ch = i + 'a';
                int freq = mp[i];

                if( ch != 'z'){
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % mod;
                }else{
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % mod;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % mod;

                }
            }
            mp = move(temp);
        }

        int ans = 0;

        for(int i=0; i<26; i++){
            ans = (ans + mp[i]) % mod;
        }

        return ans;
        
    }
};