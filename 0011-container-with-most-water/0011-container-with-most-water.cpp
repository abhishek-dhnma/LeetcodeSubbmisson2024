class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;

        int maxarea = INT_MIN;
        int currarea = 0;

        while (i < j) {

            currarea = (j - i) * min(height[i], height[j]);

            maxarea = max(maxarea, currarea);

            if (height[i] >= height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return maxarea;
    }
};