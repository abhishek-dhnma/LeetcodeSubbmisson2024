class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long left_val = llabs( (long long) dividend);

        long long right_val = llabs((long long)divisor);

        long long q = 0;

        while(left_val >= right_val){

            long long shifted_d = right_val;
            long long shifted_c = 1;

            while((shifted_d << 1) <= left_val){
                shifted_d <<= 1;
                shifted_c <<= 1;
            }

            left_val -= shifted_d;
            q += shifted_c;


        }


        bool is_neg = (dividend < 0) ^ (divisor < 0);

        if(is_neg) q = -q;
        return (int)q;
    }
};