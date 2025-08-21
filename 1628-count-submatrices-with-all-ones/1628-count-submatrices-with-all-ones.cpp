class Solution {

    
public:

int OneDArrayCount(vector<int> & vec){
        int cons = 0;
        int subCount  = 0;

        for(int & val : vec){
            if(val == 0){
                cons = 0;
            }else{
                cons++;
            }
            subCount += cons;
        }
        return subCount;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int result  = 0 ;
        for(int sr=0; sr<m; sr++){
            vector<int> vec(n,1);
            for(int er=sr; er<m; er++){

                    for(int col = 0; col<n; col++){
                        vec[col] = vec[col] & mat[er][col];
                    }

                    result += OneDArrayCount(vec);
            }
        }

        return result;
    }

};