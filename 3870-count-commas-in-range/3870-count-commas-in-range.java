class Solution {
    public int countCommas(int n) {

        // numbers less than 4 digit - zero commas 
        if(n < 1000){
            return 0;
        }

        return n - 1000 + 1;
        

        
    }
}