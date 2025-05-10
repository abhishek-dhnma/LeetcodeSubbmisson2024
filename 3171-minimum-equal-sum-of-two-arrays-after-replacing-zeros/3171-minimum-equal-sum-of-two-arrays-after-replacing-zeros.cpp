class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        long long zeroinnums1 = 0;
        long long zeroinnums2 = 0;

        for (int i = 0; i < nums1.size(); i++) {
           sum1 += nums1[i] == 0 ? 1 : nums1[i];
           zeroinnums1 += nums1[i] == 0 ? 1 : 0;
        }

        for (int i = 0; i < nums2.size(); i++) {
            sum2 += nums2[i] == 0 ? 1 : nums2[i];
           zeroinnums2 += nums2[i] == 0 ? 1 : 0;
        }

        if (sum1 < sum2 && (zeroinnums1 == 0)) {
            return -1;
        }

        if (sum2 < sum1 && (zeroinnums2 == 0)) {
            return -1;
        }

        return max(sum1, sum2);
    }
};