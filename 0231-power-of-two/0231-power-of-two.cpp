class Solution {
public:

    bool isPowerOfTwo(int n) {
        if(n == 1){
            return true;
        }

        long long p;
        int x = 1;

        while(1){

          p =  pow(2,x);

          if(p > n){
            return false;
          }else if(p == n) {

            return true;
          }

          x++;

        }
        
    }
};