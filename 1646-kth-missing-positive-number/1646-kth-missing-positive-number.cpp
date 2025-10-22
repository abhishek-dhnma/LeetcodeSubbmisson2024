class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        unordered_set<int> save;
        int n = arr.size();

        for(int i=0; i<n; i++){
            save.insert(arr[i]);
        }

        int c = 0;
        int ans;

        int i = 1;

        while(true){

            if(save.find(i) == save.end()){
                ans = i;
                c++;
                if(c==k){
                    return ans;
                }
            }

            i++;

        }

        return ans;
        
    }
};