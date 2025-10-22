class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        unordered_set<int> save(arr.begin(), arr.end());
        

        int count = 0;
        int curr = 0;

        

        while(count < k){

            curr++;

            if(save.find(curr) == save.end()){
                count++;
                
            }
        }

        return curr;
        
    }
};