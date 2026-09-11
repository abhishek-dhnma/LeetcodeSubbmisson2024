class Solution {
    public int[] findEvenNumbers(int[] digits) {
        

        int n = digits.length;

        

        Set<Integer> uniqueNumber = new TreeSet<>();

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                    for(int k=0; k<n; k++){
                        
                           int a = digits[i];
                           int b = digits[j];
                           int c = digits[k];

                           if(i==j || j == k || k == i) continue;

                           if(a==0) continue;

                            if(c%2 != 0) continue;

                            int d = (a*100) + (b*10) + c;
                            uniqueNumber.add(d);

                        
                    }



                }

            }

            
        



        
        int[] ans = new int[uniqueNumber.size()];

int idx = 0;
for (int num : uniqueNumber) {
    ans[idx++] = num;
}

return ans;


    }
}