class Solution {
public:
    int smallestRepunitDivByK(int k) {

        int rem = 0;

        for(int L=1; L<=k; L++){

            rem = (rem * 10 + 1) % k;

            if(rem == 0){
                return L;
            }
        }

        return -1;
        
    }
}; 