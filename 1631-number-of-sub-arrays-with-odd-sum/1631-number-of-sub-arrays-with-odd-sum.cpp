class Solution {
public:
    const int M = 1000000007;
    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();

        long long countE = 1;
        long long countO = 0;

        long long result =0;
        long long prefix_sum =0;

        for (int i = 0; i < n; i++) {

            prefix_sum += arr[i];

            if (prefix_sum % 2 == 0) {
                
                result = (result+ countO)%M;
                countE++;

            } else {
                result = (result+ countE)%M;
                countO++;
            }
        }

       return result;

    }
};