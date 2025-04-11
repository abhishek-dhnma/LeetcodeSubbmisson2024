class Solution {
public:
    int countSymmetricIntegers(int low, int high) {

        int count = 0;

        for(int i=low; i<= high; i++){

            int num = i;

            // 2 digits

            if(num >= 10 && num <=99 && (num%11==0)){
                count++;
            }

            if(num >= 1000 && num <= 9999){


            int s1 =   (( num/100 ) % 10)  + ( num/1000 );
            int s2 =   (( num/10 ) % 10)  + (( num/1 ) % 10); 

            if(s1 == s2) {
                count++;
            }


            }




        }

        return count;
        
    }
};