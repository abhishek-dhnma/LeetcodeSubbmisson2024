class Solution {
public:
bool isPossible(vector<int>& nums, int mid, int k){
    int house = 0;
    for(int i=0; i<nums.size(); i++){

        if(nums[i] <= mid){
            house++;
            i++; // skip one/adjacent house
        }

    }

    return house >= k; // we managed to rob atleast k houses

}
    int minCapability(vector<int>& nums, int k) {

        int n = nums.size();

        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int result = r;

        while(l <= r){

            int mid = l + (r-l)/2;

            if(isPossible(nums, mid, k)){

                result = mid;
                r = mid -1;
            }else{
                l = mid +1 ;
            }

        }

        return result;

        
    }
};