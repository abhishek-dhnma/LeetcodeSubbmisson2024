class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        int i = 0;
        int j = 0;

        int maxVal = 0;
        int currVal = 0;

        unordered_map<int, int> mp;

        while (j < n) {

            mp[fruits[j]]++;
            currVal++;

            if (mp.size() >= 3) {
                maxVal = max(currVal - 1, maxVal);
                while (i < n) {
                    mp[fruits[i]]--;
                    currVal--;
                    if (mp[fruits[i]] == 0) {
                        mp.erase(fruits[i]);
                        i++;
                        break;
                    }
                    i++;
                }
            }
            maxVal = max(currVal, maxVal);

            j++;
        }
        return maxVal;
    }
};