class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

         digits[n-1] += 1;

        int carry = digits[n-1]/10;

        if(carry) digits[n-1] = 0;

        for(int i=n-2; i>= 0; i--){

            digits[i] += carry;

            carry = digits[i]/10;

            if(carry) digits[i] = 0;

        }

        vector<int> ans(n+1);

        if(carry){

            ans[0] = carry;

            for(int i=1; i<n+1; i++){
               ans[i] = digits[i-1];
            }

            return ans;

        }

        return digits;
 
    }
};