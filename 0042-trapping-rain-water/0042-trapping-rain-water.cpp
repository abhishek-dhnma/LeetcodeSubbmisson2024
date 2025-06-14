class Solution {
public:

    int solve(vector<int>& height, int n){


        vector<int> lmax(n,0);
        vector<int> rmax(n,0);

        int lmos = height[0];
        for(int i=0; i<n; i++){
            lmax[i] = max(lmos, height[i]);
            lmos = lmax[i];
        }

        int rmos = height[n-1];
        for(int i=n-1; i>=0; i--){
            rmax[i] = max(rmos, height[i]);
            rmos = rmax[i];
        }


    
        int ans = 0;

        for(int i=0; i<n; i++){
            ans += min(lmax[i], rmax[i]) - height[i];
        }


        return ans;


    }

    int trap(vector<int>& height) {

        return solve(height, height.size());
        
    }
};