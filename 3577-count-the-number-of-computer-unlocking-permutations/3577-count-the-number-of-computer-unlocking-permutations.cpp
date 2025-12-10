class Solution {
public:
    int countPermutations(vector<int>& complexity) {

        int M = 1000000007;

        long long ans = 1;
        int n = complexity.size();

        for(int i=1; i<n; i++){

            if(complexity[0] >= complexity[i]) return 0;

            ans *= i;
            ans %= M;
        }

        return ans;
        
    }
};