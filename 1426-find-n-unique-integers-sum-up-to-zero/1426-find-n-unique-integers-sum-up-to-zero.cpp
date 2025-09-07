class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> ans(n);

        int l = 0;
        int r = n - 1;

        int mid = n / 2;
        cout << mid;

        bool isEven = true;

        (n % 2 == 0) ? isEven = true : isEven = false;

        for (int i = 0; i < n; i++) {

            if (i == mid) {

                if (isEven) {
                    ans[i] = 1;
                } else {
                    ans[i] = 0;
                }

            } else if (i < mid) {

                ans[i] = -(mid - i);

            } else if (i > mid) {

                if (isEven) {
                    ans[i] = -(mid - i) + 1;

                } else {
                    ans[i] = -(mid - i);
                }
            }
        }

        return ans;
    }
};