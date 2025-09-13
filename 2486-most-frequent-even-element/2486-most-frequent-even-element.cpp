class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){

            if( nums[i]%2 == 0){ // its a even number

            freq[nums[i]]++;

            }
        }

        if(freq.empty()) return -1;

        // half part completed

        for(auto & n : freq){
            cout << n.first << " :  " << n.second << endl;
        }

        // find frquencies and tie ann  return smalles one

        int mostfreq = -1;

        int count = 0;

        for(auto & n : freq){

            int val = n.first;
            int f = n.second;

            if( f > count || (f == count && val < mostfreq) ){

                count = f;
                mostfreq = val;
            }




        }


        return mostfreq;



        
    }
};