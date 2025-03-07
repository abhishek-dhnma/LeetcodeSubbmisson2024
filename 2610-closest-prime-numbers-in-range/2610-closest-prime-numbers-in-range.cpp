class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        const int N = 1e6 +1;
        vector<bool> isPrime(N,true);
        vector<int> primes;


        // Sieve of Eratosthenes to find all primes up to 10^6
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i<N; i++){
            if(isPrime[i]){
                for(int j = i*i; j<N; j+=i){
                    isPrime[j] = false;
                }
            }

        }


        // Collect primes in the range [left, right]

        for(int i=left; i<=right; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }

        if(primes.size() < 2) return {-1,-1}; // Not enough primes for a pair

        // Find the closest prime pair
        int minDiff = INT_MAX;
        pair<int, int> res = {-1, -1};

        for(int i =1; i < primes.size(); i++){
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff){
                minDiff = diff;
                res = {primes[i-1], primes[i]};
            }

        }


    return {res.first, res.second};
        
    }
};