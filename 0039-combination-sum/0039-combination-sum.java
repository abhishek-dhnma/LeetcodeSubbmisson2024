class Solution {

    public void solve(int[] candidates, int target, int i, List<Integer> list, List<List<Integer>> ans){

        // Base Case 1 : target is 0
        if(target == 0){
            ans.add(new ArrayList<>(list));
            return;
        }


        // Base Case 2 : target is -ve or out of index

        if(i >= candidates.length || target < 0){
            return;
        }


        // Pick current index - candidates
        if(candidates[i] <= target){
            list.add(candidates[i]);
            solve(candidates, target - candidates[i], i, list, ans );
            list.removeLast();
        }

        // Don't Pick
        solve(candidates, target, i +1, list, ans);


    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // The Pick/Don't-Pick Approach
        //Instead of looping through all remaining elements, you make exactly two decisions for the current element at index i:
        //Pick the element: Add nums[i] to your list and stay at index i (since numbers can be reused).
        //Don't pick the element: Skip nums[i] and move to index i + 1

        Arrays.sort(candidates);

        List<List<Integer>> ans = new ArrayList<>();

        solve(candidates, target, 0, new ArrayList<>(), ans);

        return ans;
        
        
    }
}