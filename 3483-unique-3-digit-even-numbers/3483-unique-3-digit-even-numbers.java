class Solution {
    public int totalNumbers(int[] digits) {

        int n = digits.length;

        Set<Integer> uniqueNumber = new HashSet<>();

        for(int i=0; i<n; i++){
            int d;
            
            if(digits[i] != 0){
                d = digits[i];
            }else{
                continue;
            }

            for(int j=0; j<n; j++){

                if(i != j){
                    
                    d = (d * 10) + digits[j] ;

                    for(int k=0; k<n; k++){
                        if(i != k && k != j ){
                            
                            if(digits[k] % 2 ==0){
                                d = (d*10) + digits[k] ;

                                if(!uniqueNumber.contains(d)){
                                    uniqueNumber.add(d);
                                }
                            d /= 10;


                            }

                        }
                    }

                    d /=10;

                }

            }

            
        }


        return uniqueNumber.size();


        
    }
}