class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int n = arr.size();
        int oddCount = 0;

        for(int i=0; i<n; i++){
            (arr[i]%2 != 0) ? oddCount++ : oddCount=0;

            if(oddCount >= 3 ){
                return true;
            }
        }

        return false;        
    }
};