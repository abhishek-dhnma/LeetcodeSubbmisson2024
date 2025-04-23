class Solution {
public:
    // ✅ Renamed for clarity
    int sumOfDigits(int n) {
        int sum = 0;
        while (n != 0) {
            int last = n % 10;
            sum += last;
            n /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> mp;

        // ✅ Step 1: Just loop through numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            int digitSum = sumOfDigits(i);
            mp[digitSum].push_back(i);
        }

        // ✅ Step 2: Find the maximum group size
        int maxGroupSize = 0;
        for (auto& [k, v] : mp) {
            maxGroupSize = max(maxGroupSize, (int)v.size());
        }

        // ✅ Step 3: Count how many groups have that size
        int count = 0;
        for (auto& [k, v] : mp) {
            if (v.size() == maxGroupSize) {
                count++;
            }
        }

        return count;
    }
};
