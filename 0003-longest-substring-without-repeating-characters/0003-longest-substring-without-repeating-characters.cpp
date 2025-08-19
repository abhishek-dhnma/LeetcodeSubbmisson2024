class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        if(n == 0) return 0;

        

        int i=0;
        int j=0;

        int maxLen = 0;

        unordered_set<char> st;

        while(j<n){

            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                maxLen = max(maxLen, j - i+1);
                j++;
            }else{
                
                st.erase(s[i]);
                i++;
            }

        }


        return maxLen;
    }
};