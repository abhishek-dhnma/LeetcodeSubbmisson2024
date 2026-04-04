/*
 * TWO SUM - One Pass Hash Map
 * 
 * KEY INSIGHT: For each element, we don't store the element itself.
 * We store its COMPLEMENT (target - nums[i]).
 * So when a future element matches a stored complement, we found our pair.
 *
 * TRICK: Check FIRST, Insert AFTER
 * - Checking first prevents self-pairing (e.g. [2,2] t=4 works naturally)
 * - Inserting after means no overwrite issues with duplicates
 * - Early exit as soon as pair is found (no need to scan full array)
 *
 * Time:  O(n)     - single pass
 * Space: O(n)     - map stores at most n complements
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // stores complement -> index
        // key   = target - nums[i]  (what we're looking for in future)
        // value = i                 (where we saw the other half)
        unordered_map<int, int> seenBefore;

        for(int i = 0; i < nums.size(); i++){

            // STEP 1: CHECK
            // if current number exists as a complement stored earlier
            // it means some previous element was looking for exactly nums[i]
            if(seenBefore.count(nums[i])){
                return {seenBefore[nums[i]], i};  // {earlier index, current index}
            }

            // STEP 2: INSERT (only if no match found yet)
            // store what the CURRENT element needs from a future element
            // if nums[i]=3 and target=9, we store 6->i
            // meaning "index i needs a 6 to complete the pair"
            seenBefore[target - nums[i]] = i;
        }

        return {}; // never reaches here (problem guarantees one solution)
    }
};