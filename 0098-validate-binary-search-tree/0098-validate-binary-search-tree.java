class Solution {

    /**
     * Recursively validates whether the subtree rooted at `root` satisfies
     * the BST property, given the valid open range (minn, maxx) inherited
     * from ancestors.
     *
     * Why bounds instead of just comparing to immediate parent/children?
     * The BST property is transitive across ALL ancestors, not just the
     * direct parent. e.g. in tree [10,5,15,1,12], node 12 is > its parent 5,
     * but still invalid because it violates ancestor 10's constraint
     * (12 > 10, but 12 sits in 10's left subtree, so it must be < 10).
     * Bounds-passing carries that ancestor constraint down the recursion.
     *
     * Why `long` and not `int` for minn/maxx?
     * Sentinels must sit strictly outside any value a node could legally
     * hold. If we used Integer.MIN_VALUE/MAX_VALUE as int sentinels, a
     * single node whose actual value equals one of those extremes would
     * incorrectly fail the check (root.val > minn becomes MIN_VALUE >
     * MIN_VALUE, which is false). Widening to `long` guarantees the
     * sentinel can never collide with a real int node value.
     */
    public boolean validTree(TreeNode root, long minn, long maxx) {

        // BASE CASE: an empty subtree trivially satisfies BST property
        // (vacuous truth — no nodes to violate anything)
        if (root == null) return true;

        // Check current node against inherited bounds, then recurse.
        // Short-circuit && means we bail early on first violation —
        // no wasted recursion once a subtree is already known invalid.
        return (root.val > minn) && (root.val < maxx)
            // Left subtree: upper bound tightens to root.val
            // (everything left of root must be strictly less than root)
            && validTree(root.left, minn, root.val)
            // Right subtree: lower bound tightens to root.val
            // (everything right of root must be strictly greater than root)
            && validTree(root.right, root.val, maxx);
    }

    public boolean isValidBST(TreeNode root) {
        // Seed the recursion with the widest possible range —
        // root has no ancestor constraints yet, so (-∞, +∞).
        return validTree(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}