class Solution {
public:

    bool canRepairAll(vector<int>& ranks, int cars, long long mid){


        long long time = 0;
        for (int rank : ranks){
            time += sqrt(mid/rank); // Number of cars this mechanic can repair
            if(time >= cars) return true;
        }

        return time >= cars;

    }


    long long repairCars(vector<int>& ranks, int cars) {

        // Time Range
        long long l = 1;
        int maxR = *max_element(ranks.begin(), ranks.end());
        long long r = (long long)maxR * cars * cars ;

        long long ans = -1;

        while(l <= r){
            long long mid = l + (r-l)/2;

            if(canRepairAll(ranks, cars, mid)){
                ans = mid;
                r = mid-1;
            }else{  
                l = mid +1;
            }
        }

        return ans;
        
    }
};