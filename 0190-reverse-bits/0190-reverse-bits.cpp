class Solution {
public:
    int reverseBits(int n) {

        

        long long  ans = 0;


        for (int i = 0; i < 32; i++) {
    int bit = (n >> (31 - i)) & 1;   // extract bit
    ans |= (bit << i);               // place it
}

        return ans;
        
    }
};