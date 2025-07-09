class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {

        vector<int> freeTimes;
        int n = startTime.size();
        freeTimes.push_back(startTime[0]);

        for (int i = 1; i < n; i++) {
            freeTimes.push_back(startTime[i] - endTime[i - 1]);
        }

        freeTimes.push_back(eventTime - endTime[endTime.size() - 1]);

        // sliding window

        int i = 0;
        int j = 0;
        int maxSum = 0;
        int currSum = 0;

        int s = freeTimes.size();

        while (j < s) {

            currSum += freeTimes[j];

            while (i < s && j - i + 1 > k + 1) {
                currSum -= freeTimes[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;
    }
};