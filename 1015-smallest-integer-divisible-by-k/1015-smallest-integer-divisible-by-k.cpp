class Solution {
public:
    int smallestRepunitDivByK(int k) {

        int rem = 0;

        unordered_set<int> st;

        int i = 1;
        while(true){

            rem = ((rem * 10) + 1) % k;

            if(rem == 0){
                return i;
            }else if(st.find(rem) != st.end() ){
                break;
            }else{
                st.insert(rem);
            }
            i++;

        }

        return -1;
        
    }
}; 