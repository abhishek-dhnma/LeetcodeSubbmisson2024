class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();


        if(m > n) return -1;
        if(m == 0) return 0;


        int i = 0;

        while(i<=n-m){

          if(haystack.substr(i,m) == needle){
            return i;
          }

          i++;

        }

        return -1;

    }
};