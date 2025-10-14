class Solution {
public:

    bool solve(vector<int>& nums, int k){

        int n = nums.size();

        if(n == 2 && k ==1){
            return true;
        }

        // edge case
        if(k*2 > n){
            return false;
        }

        // outer loop

        for(int i=0; i<n; i++){

            if(n-i < k*2){
                return false;
            }

            
            // window1
            int w1 = k-1;
            int x = i;
            bool ok1 = true;
            while(w1--){
                if(k>1 && nums[x] >= nums[x+1]){
                    ok1 = false;
                    break;
                }
                x++;
            }


            // window2
            int w2 = k-1;
            int y = i + k;
            bool ok2 = true;
            while(w2--){
                if(k>1 && nums[y] >= nums[y+1]){
                    ok2 = false;
                    break;
                }
                y++;
            }


            if(ok1 && ok2){
                return true;
            }
            
        }

        return false;
    }


    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

      return solve(nums, k);
        
    }
};