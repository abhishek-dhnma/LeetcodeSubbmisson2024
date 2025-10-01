class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();


        if(m > n) return -1;
        int i = 0;

        while(i<n){

          if(i + m > n) return -1;

          string chk = haystack.substr(i,m);

          if(chk == needle){
            return i;
          }

          i++;

        }


        return -1;

        
    }
};