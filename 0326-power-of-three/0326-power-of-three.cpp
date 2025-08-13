class Solution {
public:
    bool isPowerOfThree(int n) {


        for(int i=0; i<32; i++){
            long p = pow(3,i);

            if(n == p )
            {
                return true;
            }
        }

        return false;
        
    }
};