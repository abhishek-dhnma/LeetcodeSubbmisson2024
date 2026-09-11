class Solution {
    public int totalNumbers(int[] digits) {

        int n = digits.length;

        Set<Integer> uniqueNumber = new HashSet<>();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){

                        int a = digits[i];
                        int b = digits[j];
                        int c = digits[k];

                        if(i == j || k == j || i == k) continue;

                        if( a == 0) continue;

                        if(c%2 != 0) continue;

                        int d = (a * 100) + (b * 10) + c ;

                        uniqueNumber.add(d);
                           
                    }

                }

            
            
            
            
            }

             return uniqueNumber.size();


            
        }

       
}