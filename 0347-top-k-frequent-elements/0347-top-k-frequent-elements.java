class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        // bucket sorting technique -> TC:O(N) SC:O(N) 

        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int n = nums.length;
        for(int i=0; i<n; i++){
            freqMap.put(nums[i], freqMap.getOrDefault(nums[i], 0) + 1);
        }

        // bucket -> list of list 
        List<List<Integer>> buckets = new ArrayList<>(n); // capacity = n but size = 0
        for(int i=0; i<n; i++){
            buckets.add(new ArrayList<>());
        }

        // freqMap -> Buckets index = frequency and Buckets Value = List contains all nums values having same index frquency like Map({1, 3}, {2,3}) = [[],[],[1,2]]

        // insert or fill 
        for(Map.Entry<Integer, Integer> map : freqMap.entrySet() ){

            buckets.get(map.getValue()-1).add(map.getKey());

        }


        // retrive 

        int[] ans = new int[k];

        int a = 0;

        for(int i=n-1; i>=0 ; i--){
            int s = buckets.get(i).size();
            for(int j=s-1; j>=0; j--){
                ans[a] = buckets.get(i).get(j);
                a++;
                if(a >= k){
                    return ans;
                }
            }
        }

        return ans;
        
    }
}