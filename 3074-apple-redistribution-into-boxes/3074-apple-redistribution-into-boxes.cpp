class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int ans = 0;

        int n = apple.size();
        int m = capacity.size();

        sort(capacity.begin(), capacity.end(), greater<int>());

        int totalapple = 0;

        for (int i = 0; i < n; i++) {
            totalapple += apple[i];
        }

        cout << totalapple;

        for (int i = 0; i < m; i++) {

            int check = totalapple - capacity[i];

            if (check > 0) {
                ans++;
            } else {
                break;
            }

            totalapple = check;
        }

        return ans + 1;
    }
};