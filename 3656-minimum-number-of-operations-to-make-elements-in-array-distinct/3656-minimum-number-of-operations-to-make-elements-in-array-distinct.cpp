class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_set<int> key;
        int n = nums.size();

        int i = 0;

        bool isDistinct = true;

        int result = 0;

        while(i < n ){

            if(key.find(nums[i]) == key.end() ){
                key.insert(nums[i]);
                
            }else{
                isDistinct = false;
                key.clear();
                result++;
                
            }

            if(!isDistinct){

                i =  3 * result;
                isDistinct = true;
                continue;

            }

            i++;

        }

        return result;
        
    }
};
