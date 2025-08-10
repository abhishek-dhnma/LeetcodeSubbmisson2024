class Solution {
public:
    int climbStairs(int n) {

        if(n < 0) return 0;
        if(n == 1) return 1;

        int pre1=1;
        int pre2=1;
        int curr = 0;


        for(int i=2; i<=n; i++){

            curr  = pre1 + pre2;
            pre1 =  pre2;
            pre2 = curr;
        }

        return pre2;
    }
};