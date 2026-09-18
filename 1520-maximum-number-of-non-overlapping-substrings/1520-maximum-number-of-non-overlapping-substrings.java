class Solution {

    public int check(String s, int i, int[][] bounds){

        int start = bounds[i][0];
        int end = bounds[i][1];

        for(int j=start; j<=end; j++){

            int charIdx = s.charAt(j) - 'a';

            if(bounds[charIdx][0] < start){
                return -1; // invalid interval
            }

            end = Math.max(end, bounds[charIdx][1]);

        }

        return end;


    }

    public List<String> maxNumOfSubstrings(String s) {
        
        // creating the array with first and last occurence of character present in s
        int[][] bounds = new int[26][2];

        for(int i=0; i<26; i++){
            bounds[i][0] = -1;
            bounds[i][1] = -1;
        }

        for(int i=0; i<s.length(); i++){
           int charIdx = s.charAt(i)-'a';
            if(bounds[charIdx][0] == -1){
                bounds[charIdx][0] = i;
            }
                bounds[charIdx][1] = i;
            
        }
        //-----------------
        // checking and creating valid substrings

        List<int[]> list = new ArrayList<>();

        for(int i=0; i<26; i++){

            // means character present in s
           if(bounds[i][0] != -1){ 
            int validEnd = check(s, i, bounds);
            if( validEnd != -1){
                list.add(new int[]{bounds[i][0], validEnd});
            }
           }
        }

        // Greedy algorithm - interval scheduling by end index

        Collections.sort(list, (a,b) -> (a[1] - b[1]));

        // ans non-overlapping substrins

        //for(int[] intervals : list){
        //    System.out.println(intervals[0] + "-" + intervals[1]);
        //    System.out.println("-------------");
        //}

        List<String> ans = new ArrayList<>();
        int right = -1;

        for(int[] intervals : list){

            if(intervals[0] > right){
                right = intervals[1];
                ans.add(s.substring(intervals[0], intervals[1]+1));
            }
        }

        return ans;
        
    }

}