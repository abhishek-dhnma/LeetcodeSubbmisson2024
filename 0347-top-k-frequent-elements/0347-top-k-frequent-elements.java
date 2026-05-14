class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        /*
         * APPROACH: Bucket Sort
         * 
         * Key Insight: frequency of any element can be at most n (if all elements are same).
         * So instead of sorting by frequency (O(n log n)), we use frequency as an index
         * into a bucket array — giving us O(n) time.
         *
         * Steps:
         * 1. Build frequency map         → O(n)
         * 2. Place elements into buckets → O(n)  [index = frequency - 1]
         * 3. Read buckets right to left  → O(n)  [highest freq first]
         *
         * TC: O(n)  — no sorting involved
         * SC: O(n)  — freqMap + buckets both scale with input size
         */

        // Step 1: Count frequency of each number
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            freqMap.put(nums[i], freqMap.getOrDefault(nums[i], 0) + 1);
        }

        // Step 2: Initialize n buckets
        // bucket at index i holds all numbers with frequency (i+1)
        // NOTE: new ArrayList<>(n) sets capacity but NOT size — explicit init loop is mandatory
        // Skipping this would cause NullPointerException on bucket.get(i).add(...)
        List<List<Integer>> buckets = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            buckets.add(new ArrayList<>());
        }

        // Step 3: Fill buckets
        // e.g. num=3 appears 4 times → goes into buckets.get(3) [index = freq - 1]
        for (Map.Entry<Integer, Integer> map : freqMap.entrySet()) {
            buckets.get(map.getValue() - 1).add(map.getKey());
        }

        // Step 4: Collect top k elements
        // Traverse from highest frequency bucket (n-1) down to 0
        // Early return once k elements are collected — avoids nested break complexity
        int[] ans = new int[k];
        int a = 0;
        for (int i = n - 1; i >= 0; i--) {
            int s = buckets.get(i).size();
            for (int j = s - 1; j >= 0; j--) {
                ans[a] = buckets.get(i).get(j);
                a++;
                if (a >= k) return ans; // collected k elements, done
            }
        }

        return ans;
    }
}