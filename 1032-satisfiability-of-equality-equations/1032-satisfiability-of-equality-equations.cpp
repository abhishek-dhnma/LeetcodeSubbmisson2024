class Solution {
public:

    vector<int> parent;
    vector<int> rank;


    int Find(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = Find(parent[x]);  
    }

    void Union(int x, int y){
        int x_parent = Find(x);
        int y_parent = Find(y);

        if(x_parent == y_parent){
            return;
        }

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;

        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }


    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);
        rank.resize(26, 0);

        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        // union of equal chars
        for(auto & eq : equations){
            if(eq[1] ==  '='){

                Union(eq[0] - 'a', eq[3] - 'a');

            }
        }

        for(auto & eq : equations){
            if(eq[1] == '!'){
               int first_parent = Find(eq[0] - 'a');
               int second_parent = Find(eq[3] - 'a');

               if(first_parent == second_parent){
                return false;
               }
            }
        }

        return true;
        
    }
};