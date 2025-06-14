class Solution {
public:
    
    int WaterTrapped(vector<int> building_Heights, int n){

    vector<int> lmax(n,0);
    vector<int> rmax(n,0);

    int leftmaxsofar = building_Heights[0];
    for(int i=0; i<n; i++){
        lmax[i] = max(leftmaxsofar, building_Heights[i]);
        leftmaxsofar = lmax[i];
    }




        int rightmaxsofar = building_Heights[n-1];
    for(int i=n-1; i>=0; i--){
        rmax[i] = max(rightmaxsofar, building_Heights[i]);
        rightmaxsofar = rmax[i];
    }


    vector<int> ans(n, 0);

    for(int i=1; i<n-1; i++){

        ans[i] = min(lmax[i], rmax[i]) - building_Heights[i];
    }


    int TotalWaterTrappedBetweenBuildings = 0;

    for(auto xx : ans){
        TotalWaterTrappedBetweenBuildings += xx;
    }

    return TotalWaterTrappedBetweenBuildings;

}
    int trap(vector<int>& height) {
        
         
        return WaterTrapped(height, height.size());
    }
};