class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        vector<int> res(n);
        
        int i =0, j = n-1;
        int x = 0, y = n-1;
        
        while(i < n && j >=0){
            if(nums[i] < pivot){
                res[x] = nums[i];
                x++;
            }

            if(nums[j] > pivot){
                res[y] = nums[j];
                y--;
            }

            i++;
            j--;

        }

        while( x <= y){

            res[x] =  pivot;
            res[y] = pivot;
            x++;
            y--;
        }

        return res;
    }
};