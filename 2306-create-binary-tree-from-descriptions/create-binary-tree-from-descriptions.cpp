/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* Solve(vector<vector<int>>& descriptions) {

        unordered_map<int,TreeNode*> Hashtable;
        unordered_set<int> RootSetParent;

        int Parent, Child; 

        for(int i=0; i<descriptions.size(); i++){
            Parent = descriptions[i][0];
            Child = descriptions[i][1];


            if( Hashtable.find(Parent) == Hashtable.end() ){
                Hashtable[Parent] = new TreeNode(Parent);
            }
            if( Hashtable.find(Child) == Hashtable.end() ){
                Hashtable[Child] = new TreeNode(Child);
            }
            RootSetParent.insert(Child);
        }

        TreeNode* head;
        for(int i=0; i<descriptions.size(); i++){
            if(descriptions[i][2]){ //left
                Hashtable[descriptions[i][0]] -> left = Hashtable[descriptions[i][1]];
            }else{ //right
                Hashtable[descriptions[i][0]] -> right = Hashtable[descriptions[i][1]];
            }

            if(RootSetParent.find(descriptions[i][0]) == RootSetParent.end() ){
                head =  Hashtable[descriptions[i][0]];
            }
            
        }


        return head;
    }
    

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        return Solve(descriptions);
        
    }
};