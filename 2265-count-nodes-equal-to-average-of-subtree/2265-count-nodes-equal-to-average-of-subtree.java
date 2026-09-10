/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) { 
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {


        int ans = 0;

        public int[] Average(TreeNode root){

        if(root == null) return new int[]{0,0};

        int[] leftarray = Average(root.left);
        int[] rightarray = Average(root.right);

        int N = root.val + leftarray[0] + rightarray[0];
        int D = 1 +  leftarray[1] + rightarray[1];

        if((N/D) == root.val){
            ans++;
        }

        return new int[]{N, D};
    }


    public int averageOfSubtree(TreeNode root) {
        
        Average(root);  
        return ans;

    }
}