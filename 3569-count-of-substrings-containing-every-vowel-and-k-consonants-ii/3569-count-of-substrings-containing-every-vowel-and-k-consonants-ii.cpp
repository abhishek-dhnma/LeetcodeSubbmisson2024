class Solution {
public:
bool isVowel(char & c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
    long long countOfSubstrings(string word, int k) {

        int n = word.length();

        unordered_map<char, int> mp;

        vector<int> nextCons(n);
        int lastConsidx = n;

        for(int i=n-1; i>=0; i--){
            nextCons[i] = lastConsidx;
            if(!isVowel(word[i])){
                lastConsidx = i;
            }
        }


        int  i=0;
        int j=0;
        long long count = 0;
    int cons = 0;

    // TC : O(2*n) ~ O(n)
        while(j < n){

            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                cons++;
            }


            while(cons > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else {
                    cons--;
                }
                i++;
            }


            while(i<n && mp.size() == 5 && cons == k){
                int idx = nextCons[j];
                count += idx - j;
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;

            }

            j++;

        }


    return count;
        
    }
};