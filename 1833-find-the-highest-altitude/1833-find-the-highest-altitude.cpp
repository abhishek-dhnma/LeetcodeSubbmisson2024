class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int prefixSum = 0;
        int ans = 0;
        int n = gain.size();

        for(int i=0; i<n; i++){
            prefixSum = prefixSum + gain[i];

            ans = max(prefixSum, ans);
        }

        return ans;
        
    }
};