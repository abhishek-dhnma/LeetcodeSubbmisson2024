class Solution {
public:
    int countCommas(int n) {

        int totalCommas = 0;
        
        if( n >= 1000){

            totalCommas += (n - 1000 + 1);

        }

        return totalCommas;
    }
};