class Solution {
    
    // ==========================================
    // 1. THE NODE (The "Super Clipboard")
    // ==========================================
    class SegNode {
        int totalMod;       // The remainder of multiplying EVERY number in this chunk
        int[] prefixCounts; // The remainders of all valid prefixes starting inside this chunk
        
        public SegNode(int k) {
            prefixCounts = new int[k];
        }
    }

    SegNode[] tree;
    int k;
    int n;

    public int[] resultArray(int[] nums, int k, int[][] queries) {
        this.n = nums.length;
        this.k = k;
        
        // A segment tree requires 4 * N space to safely hold all chunks
        this.tree = new SegNode[4 * n];
        
        // Pre-fill the tree with empty nodes so we don't have to create them later
        for (int i = 0; i < 4 * n; i++) {
            tree[i] = new SegNode(k);
        }
        
        // Build the initial tree from the starting array
        build(1, 0, n - 1, nums);
        
        int[] result = new int[queries.length];
        
        for (int i = 0; i < queries.length; i++) {
            int index = queries[i][0];
            int value = queries[i][1];
            int start = queries[i][2];
            int targetX = queries[i][3];
            
            // Action 1: Update the single number in the tree (O(log N))
            update(1, 0, n - 1, index, value);
            
            // Action 2: Query the range from `start` to the end of the array (O(log N))
            SegNode queryResult = query(1, 0, n - 1, start, n - 1);
            
            // The answer is simply the count of prefixes that resulted in our target remainder 'x'
            result[i] = queryResult.prefixCounts[targetX];
        }
        
        return result;
    }

    // ==========================================
    // THE FACTORY: How we glue two chunks together
    // ==========================================
    private void mergeInto(SegNode left, SegNode right, SegNode parent) {
        // 1. Combine total products
        parent.totalMod = (left.totalMod * right.totalMod) % k;
        
        // 2. Copy the prefixes from the Left chunk (they don't change)
        for (int i = 0; i < k; i++) {
            parent.prefixCounts[i] = left.prefixCounts[i];
        }
        
        // 3. THE SHIFT TRICK! (Exactly from Part I)
        // Shift the Right chunk's prefixes by the Left chunk's total product
        for (int rightRem = 0; rightRem < k; rightRem++) {
            if (right.prefixCounts[rightRem] > 0) {
                
                int shiftedRem = (left.totalMod * rightRem) % k;
                
                parent.prefixCounts[shiftedRem] += right.prefixCounts[rightRem];
            }
        }
    }
    
    // An overloaded merge that returns a brand new node (Used strictly for querying)
    private SegNode mergeForQuery(SegNode left, SegNode right) {
        SegNode tempParent = new SegNode(k);
        mergeInto(left, right, tempParent);
        return tempParent;
    }

    // ==========================================
    // 2. THE BUILD (O(N))
    // ==========================================
    private void build(int node, int L, int R, int[] nums) {
        // Base Case: We hit a single number
        if (L == R) {
            int mod = nums[L] % k;
            tree[node].totalMod = mod;
            tree[node].prefixCounts[mod] = 1;
            return;
        }
        
        int mid = L + (R - L) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        
        // Build the left and right halves recursively
        build(leftChild, L, mid, nums);
        build(rightChild, mid + 1, R, nums);
        
        // Glue them together into this current node
        mergeInto(tree[leftChild], tree[rightChild], tree[node]);
    }

    // ==========================================
    // 3. THE UPDATE (O(log N))
    // ==========================================
    private void update(int node, int L, int R, int targetIndex, int newValue) {
        // Base Case: We found the exact number to update
        if (L == R) {
            int mod = newValue % k;
            tree[node].totalMod = mod;
            
            // Clear old data and set the new remainder
            for(int i=0; i<k; i++) tree[node].prefixCounts[i] = 0;
            tree[node].prefixCounts[mod] = 1;
            return;
        }
        
        int mid = L + (R - L) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        
        // Traverse down the tree to the correct half
        if (targetIndex <= mid) {
            update(leftChild, L, mid, targetIndex, newValue);
        } else {
            update(rightChild, mid + 1, R, targetIndex, newValue);
        }
        
        // On the way back up, re-glue the chunks together so the update ripples to the top
        mergeInto(tree[leftChild], tree[rightChild], tree[node]);
    }

    // ==========================================
    // 4. THE QUERY (O(log N))
    // ==========================================
    private SegNode query(int node, int L, int R, int queryL, int queryR) {
        // Condition 1: Total Overlap. The chunk is fully inside our query range.
        if (queryL <= L && R <= queryR) {
            return tree[node];
        }
        
        int mid = L + (R - L) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        
        // Condition 2: Partial Overlap. Determine which halves we need to query.
        if (queryR <= mid) {
            return query(leftChild, L, mid, queryL, queryR);
        } 
        else if (queryL > mid) {
            return query(rightChild, mid + 1, R, queryL, queryR);
        } 
        else {
            // Condition 3: Split Overlap. We need pieces from both halves.
            SegNode leftResult = query(leftChild, L, mid, queryL, mid);
            SegNode rightResult = query(rightChild, mid + 1, R, mid + 1, queryR);
            
            // Temporarily glue them together just for this query
            return mergeForQuery(leftResult, rightResult);
        }
    }
}