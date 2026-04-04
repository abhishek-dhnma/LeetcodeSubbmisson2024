class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;


        for(int i=0; i<n; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int t = nums[i];
            int x = i+1;
            int y = n-1;

            while(x < y){

                int sum = nums[i] + nums[x] + nums[y];
                if(0 ==  sum){
                    ans.push_back({nums[i], nums[x], nums[y]});
                    while( x < y && nums[x] == nums[x+1])
                    {x++;}
                    while( x < y && nums[y] == nums[y-1]){
                        y--;
                    }

                    x++;
                    y--;
                }else if(0 < sum){

                    y--;

                }else {

                    x++;
                }
            }

        }


        return ans;
        
    }
};