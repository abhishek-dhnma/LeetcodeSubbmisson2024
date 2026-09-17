class Solution {
    public int minSumOfLengths(int[] arr, int target) {

        int n = arr.length;

        // using sliding window - find non-overlapping sub-arrays
        int i = 0;
        int j = 0;

        int currSum = 0;

        int minSum = Integer.MAX_VALUE;

        // my signpost
        int[] bestMinLengthSoFar = new int[n+1];
        Arrays.fill(bestMinLengthSoFar, Integer.MAX_VALUE);

        int currBestLen = Integer.MAX_VALUE;

        while(j < n){
            currSum = currSum + arr[j];


                while(i<=j && currSum > target){
                    currSum -= arr[i];
                    i++;
                }
            

            if(currSum == target){
                // I found One subarray which is valid
                // and I need another non-overlapping array
                // which is end at i-1 and start from 0 to i-1 any
                int currLen = j-i+1;

                if(i>0 && bestMinLengthSoFar[i - 1] != Integer.MAX_VALUE){
                      minSum = Math.min(minSum, currLen +  bestMinLengthSoFar[i-1]);
                }
                
               currBestLen = Math.min(currBestLen, currLen);
            }

            bestMinLengthSoFar[j] = currBestLen;
            j++;

        }

        return minSum == Integer.MAX_VALUE ? -1 : minSum;
        
        
    }
}