class Solution {
public:
    int maxSum(vector<int>& nums) {

        unordered_set<int> st;
        int neg = INT_MIN;
        int sum = 0;

        for (auto& n : nums) {
            if (n <=0 ) {
                neg = max(n, neg);
            }

            else 
                if ( !st.count(n) ) {
                    sum += n;
                    st.insert(n);
                
            }
        }



        return sum == 0 ? neg : sum;
    }
};