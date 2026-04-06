class Solution {
public:
    int maxArea(vector<int>& height) {

        // two pointer approach 
        int i = 0;
        int j = height.size()-1;
        int ans = 0;
        while(i < j){
            
            int area = (min(height[i], height[j])) * (j - i);

            if(height[i] < height[j]){
                i++;
            }else {
                j--;
            }

            ans = max(ans, area);

        }
        return ans;
        
    }
};