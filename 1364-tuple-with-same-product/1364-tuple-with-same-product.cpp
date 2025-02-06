class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int n = nums.size();
        if(n <= 3) return 0;
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                freq[ nums[i] * nums[j]]++;
            }
        }

        int ans = 0;

        for(const auto& [product , count] : freq){

                        if(count >=2 ){
                
                ans += count * (count-1) * 4;
            }

        }

        return ans;
        
    }
};