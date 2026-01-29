class Solution {
public:
    bool isPalindrome(int x) {

        
        if(x < 0){
            return false;
        }
        
        long tempx = (long) x;
        long num = 0;
        int place = 1;

        while(tempx){

            int rem = tempx%10;
            num = long (num * 10) + rem;
         
            tempx/=10;

        }

        return num ==  (long)x;

        
    }
};