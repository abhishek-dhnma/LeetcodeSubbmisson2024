class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i =0;
        int j = n-1;
        int area = 0;
        int maxarea = 0;
        int w;

        while(i < j){
            w = j-i;

            if(height[i] <= height[j]){
                area = w * height[i];
                i++;
            }else if(height[i] > height[j]){
                

                area = w * height[j];
                j--;
            }

            maxarea = max(area, maxarea);

        }




    return maxarea;

        
    }
};