class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

if (right < 2) return {-1, -1};  // No primes exist below 2

        // Step 1: Use Sieve of Eratosthenes to get small primes up to sqrt(10^6)
        const int N = sqrt(1e6) + 1;
        vector<bool> isPrime(N, true);
        vector<int> smallPrimes;
        
        for (int i = 2; i < N; ++i) {
            if (isPrime[i]) {
                smallPrimes.push_back(i);
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Use Segmented Sieve to mark primes in range [left, right]
        vector<bool> isSegmentPrime(right - left + 1, true);
        
        for (int prime : smallPrimes) {
            int start = max(prime * prime, (left + prime - 1) / prime * prime);
            for (int j = start; j <= right; j += prime) {
                isSegmentPrime[j - left] = false;
            }
        }

        // Step 3: Collect primes in range & find closest pair in one pass
        int prevPrime = -1, minDiff = INT_MAX;
        pair<int, int> closestPair = {-1, -1};

        for (int i = left; i <= right; ++i) {
            if (i < 2) continue;
            if (isSegmentPrime[i - left]) {
                if (prevPrime != -1 && i - prevPrime < minDiff) {
                    minDiff = i - prevPrime;
                    closestPair = {prevPrime, i};
                }
                prevPrime = i;
            }
        }

        return (closestPair.first == -1) ? vector<int>{-1, -1} : vector<int>{closestPair.first, closestPair.second};
        
    }
};