class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

vector<int> result;
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        // Only even numbers from 100 to 998
        for (int num = 100; num <= 998; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            // Check if digits a, b, c exist in freq
            vector<int> needed(10, 0);
            needed[a]++;
            needed[b]++;
            needed[c]++;

            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (needed[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(num);
        }

        return result;
        
    }
};