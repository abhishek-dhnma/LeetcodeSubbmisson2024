class Solution {
public:

    bool canRepairAll(vector<int>& ranks, int cars, long long mid){

        int i = 0;
        long long time = 0;
        while( i < ranks.size()){

            time += sqrt(mid/ranks[i]);
            i++;
        }

        return time >= cars;

    }


    long long repairCars(vector<int>& ranks, int cars) {

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