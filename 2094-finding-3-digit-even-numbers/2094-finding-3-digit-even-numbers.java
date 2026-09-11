class Solution {
    public int[] findEvenNumbers(int[] digits) {
        

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

        int x = uniqueNumber.size();
        int [] ans = new int[x];
        int i=0;



        
         // 2. Convert HashSet to a sorted TreeSet
        TreeSet<Integer> sortedSet = new TreeSet<>(uniqueNumber);

        // 3. Remove from the front one by one
        System.out.println("Removing elements from the front:");
        while (!sortedSet.isEmpty()) {
            ans[i] = sortedSet.pollFirst(); // Removes and returns the lowest element
            i++;
        }


        return ans;
    }
}