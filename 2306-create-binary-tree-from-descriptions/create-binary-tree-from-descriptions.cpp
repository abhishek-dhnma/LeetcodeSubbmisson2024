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

        for(int i=0; i<descriptions.size(); i++){
            if( Hashtable.find(descriptions[i][0]) == Hashtable.end() ){
                Hashtable[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            }
            if( Hashtable.find(descriptions[i][1]) == Hashtable.end() ){
                Hashtable[descriptions[i][1]] = new TreeNode( descriptions[i][1]);
            }
            RootSetParent.insert(descriptions[i][1]);
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