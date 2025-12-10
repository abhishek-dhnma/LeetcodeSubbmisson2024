class Solution {
public:


long long factorial_mod(int n, long long M) {
    if (n < 0) {
        // Factorial is not defined for negative numbers
        return 0; // Or throw an exception
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    // Calculate (n * factorial(n-1)) % M
    return (n * factorial_mod(n - 1, M)) % M;
}

    int countPermutations(vector<int>& complexity) {

        int n = complexity.size();

        long long modulus = 1000000007;

        auto min_it = min_element(complexity.begin()+1, complexity.end());

        int min_el =  *min_it;

        if(min_el <= complexity[0]){
            return 0;
        }

        // Calculate factorial(n_value - 1) % modulus
    long long result = factorial_mod(n - 1, modulus);

        min_el = result;

        return min_el;
        
    }
};