class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {

        HashMap<String, List<String>> map = new HashMap<>();
        for(String s : strs){
            List<Integer> keyList = new ArrayList<>(Collections.nCopies(26, 0));
            
            for(int i=0; i<s.length(); i++){

                int idx = s.charAt(i) - 'a';
                keyList.set(idx, keyList.get(idx) + 1);


            }

            StringBuilder keyString = new StringBuilder();

            for(int i=0; i<26; i++){
                keyString.append('#').append(keyList.get(i));
            }

            map.computeIfAbsent(keyString.toString(), k -> new ArrayList<>()).add(s);

        }


        return new ArrayList<>(map.values());
        
    }
}