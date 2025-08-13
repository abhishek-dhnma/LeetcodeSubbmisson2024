class Solution {
public:
    bool isPowerOfThree(int n) {

        int p = pow(3,19);


            return n > 0 && (p%n == 0);
        
    }
};