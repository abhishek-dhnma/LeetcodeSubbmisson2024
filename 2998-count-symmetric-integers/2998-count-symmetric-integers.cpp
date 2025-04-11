class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i=low; i<=high; i++){

            string dgt = to_string(i);
            int l = dgt.length();

            if(l%2 == 0){ // odd

            int n = l/2;
            int sumf = 0;
            int suml = 0;

            for(int j = 0; j<l; j++){

                if(j <n){
                    sumf += dgt[j];
                }else if( j >= n){
                    suml += dgt[j];

                }
            }

            if(sumf == suml){
                count++;
            }

            }
        }

        return count;
        
    }
}; 