class Solution {
    public int lengthOfLongestSubstring(String s) {

        int n = s.length();

        int i =0;
        int j =0;

        // HashMap <Character, Integer>
        // < character, Character_index >

        HashMap<Character, Integer> map = new HashMap<>();
        int maxAns = 0;

        while(j < n){

            if(map.containsKey(s.charAt(j))){
                i = Math.max(i, map.get(s.charAt(j))+1);
            }

            map.put(s.charAt(j), j);
            maxAns = Math.max(maxAns, j-i+1);
            j++;            


        }

        return maxAns;
        
    }
}