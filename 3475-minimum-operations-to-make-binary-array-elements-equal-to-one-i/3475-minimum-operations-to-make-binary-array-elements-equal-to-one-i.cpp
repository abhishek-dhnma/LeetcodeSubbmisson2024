class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        int flip = 0;

        for (int i = 0; i < n; i++) {

            if (!(nums[i])) {

                if ((i + 1 < n) && (i + 2 < n)) {
                    nums[i] ^= 1;
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                    flip++;
                } else {
                    flip = -1;
                }
            }
        }

        return flip;
    }
};