class Solution {
public:
long long M;

long long factorial_mod(int n) {
    if (n < 0) {
        // Factorial is not defined for negative numbers
        return 0; // Or throw an exception
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    // Calculate (n * factorial(n-1)) % M
    return (n * factorial_mod(n - 1)) % M;
}

    int countPermutations(vector<int>& complexity) {

        int n = complexity.size();

        M = 1000000007;

        auto min_el = *min_element(complexity.begin()+1, complexity.end());


        if(min_el <= complexity[0]){
            return 0;
        }

        // Calculate factorial(n_value - 1) % modulus
    long long result = factorial_mod(n - 1);

        min_el = result;

        return min_el;
        
    }
};