class Solution {
public:
    vector<int> sumZero(int n) {

        int i = 0;
        int j = n-1;

        vector<int> ans(n,0);

        int element = 1;
 
        while(i<j){

            ans[i] = element;
            ans[j] = -element;
            i++;
            j--;
            element++;

        }


        return ans;
        
    }
};