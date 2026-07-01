class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Base Case: If we reach a null node, return null
        if (root == null) return null;

        // Case 1: Both nodes are smaller -> search the left subtree recursively
        if (p.val < root.val && q.val < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        }

        // Case 2: Both nodes are larger -> search the right subtree recursively
        else if (p.val > root.val && q.val > root.val) {
            return lowestCommonAncestor(root.right, p, q);
        }

        // Case 3: Split point reached -> current root is the LCA
        else {
            return root;
        }
    }
}