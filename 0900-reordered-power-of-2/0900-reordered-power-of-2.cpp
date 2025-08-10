class Solution {
public:
    bool reorderedPowerOf2(int n) {

        string num = to_string(n);
        sort(num.begin(), num.end());


        

        for(int i=0; i<=30; i++){

            string power = to_string(1 << i);
            sort(power.begin(), power.end());


            if(num == power){
                return true;
            }

        }

        return false;
    }
};