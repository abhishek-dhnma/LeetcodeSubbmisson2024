class Solution {
public:

    pair<bool, int> binarySearch(vector<int>& numbers, int t, int start){

        int l = start;
        int r = numbers.size() - 1;

        while(l <= r){

            int mid =  l + (r-l)/2;

            if(numbers[mid] == t){
                if(mid != start-1){
                    return {true, mid};
                }else{
                    l = mid+1;
                }
            }else if(numbers[mid] > t){
                r = mid-1;
            }else{
                l = mid+1;
            }

        }

        return{false,-1};

    }

    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> ans;


        for(int i=0; i<numbers.size(); i++){
            int y = target - numbers[i];

             pair<bool,  int> chk = binarySearch(numbers, y, i+1);

            if(chk.first){
                ans.push_back(i+1);
                ans.push_back(chk.second +1);
                break;
            }   
        }

        return ans;
        
    }
};