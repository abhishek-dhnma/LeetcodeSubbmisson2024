class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // jump approach

        int i =0;
        int j=0;
        int n = s.size();
        int maxCount = 0;
        // chararcter <-> last seen
        unordered_map<char, int> mapp;
        while(j < n){


            if(mapp.find(s[j]) != mapp.end() && mapp[s[j]] >= i){
                i = mapp[s[j]] + 1;
            }

            mapp[s[j]] = j;
            maxCount = max(maxCount, j - i + 1);
            j++;

        }


        return maxCount;
        
    }
};