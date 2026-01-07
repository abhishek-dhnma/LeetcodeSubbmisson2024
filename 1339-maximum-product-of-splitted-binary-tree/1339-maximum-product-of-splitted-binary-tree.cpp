/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    // totalSum

    long globalMax = INT_MIN;

    int tsum(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + tsum(root->left) + tsum(root->right);
    }

    int solve(TreeNode* root, int totalSum) {

        if(!root) return 0;


        // left - right - root -- Postorder
        int subtree_sum = solve(root->left, totalSum) +  solve(root->right, totalSum) + root->val;

        long remainingSum = ((totalSum - subtree_sum) *  (long long) subtree_sum);
        globalMax = max(remainingSum, globalMax);

        return subtree_sum;
    }

public:
    int maxProduct(TreeNode* root) {

        int MOD = 1000000007;

        int totalSum = tsum(root);

       // cout << totalSum;

        solve(root, totalSum);

        return globalMax % MOD;
    }
};