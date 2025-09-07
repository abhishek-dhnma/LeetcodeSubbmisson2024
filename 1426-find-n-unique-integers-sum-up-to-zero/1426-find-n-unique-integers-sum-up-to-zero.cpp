class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> ans(n);

        int l = 0;
        int r = n-1;

        int mid = n/2;
        cout << mid;

        if(n%2 == 0){
            // even



            for(int i=0; i<n; i++){

                if(i ==  mid){
                    ans[i] = 1;
                }else if(i < mid ){

                    ans[i] = - (mid - i);


                }else if( i > mid){

                    ans[i] = - (mid - i) + 1;


                }
            }

        }else{

            //odd

            

            for(int i=0; i<n; i++){

                if(i ==  mid){
                    ans[i] = 0;
                }else if(i < mid){

                  ans[i] = -(mid - i);


                }else if ( i > mid){

                    ans[i] = - (mid - i);

                }


            }


        }


        return ans;
        
    }
};