class Solution {
    public int longestConsecutive(int[] nums) {

          int n = nums.length;
        if(n == 0) return 0;

        // O(n) — add all elements for O(1) lookup
        HashSet<Integer> set = new HashSet<>();
        for(int num : nums) set.add(num);

        int ans = 0;

        for(Integer s : set){

            // only process sequence starts — discard if left neighbor exists
            // left neighbor means this element is already part of an earlier sequence
            if(!set.contains(s- 1)){

                int currval = s;
                int currcount = 1;

                // extend sequence as far right as possible
                while(set.contains(currval + 1)){
                    currcount++;
                    currval++;
                }

                ans = Math.max(ans, currcount);
            }
        }

        return ans;
        
    }
}