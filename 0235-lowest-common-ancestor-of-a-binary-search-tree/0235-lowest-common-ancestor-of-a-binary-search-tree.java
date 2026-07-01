class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        // Traverse the tree until we hit a null node
        while (root != null) {

            // Case 1: Both target nodes are smaller than the current root.
            // This means their lowest common ancestor must be in the left subtree.
            if (p.val < root.val && q.val < root.val) {
                root = root.left; // Move the pointer to the left child
            }

            // Case 2: Both target nodes are larger than the current root.
            // This means their lowest common ancestor must be in the right subtree.
            else if (p.val > root.val && q.val > root.val) {
                root = root.right; // Move the pointer to the right child
            }

            // Case 3: The Split Point!
            // One node is smaller/equal and the other is larger/equal to the root.
            // This current node is the lowest common ancestor.
            else {
                return root;
            }
        }

        // Return null if the tree is empty or nodes aren't found
        return null; 
    }
}