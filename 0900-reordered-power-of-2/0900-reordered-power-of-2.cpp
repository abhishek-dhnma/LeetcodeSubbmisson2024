class Solution {
public:

    unordered_set<string> st;

    void generate(){

        for(int i=0; i<=30; i++){

            string power = to_string(1 << i);
            sort(power.begin(), power.end());

            st.insert(power);
        }

    }

    bool reorderedPowerOf2(int n) {
        generate();

        string num = to_string(n);
        sort(num.begin(), num.end());

        if(st.count(num)){
            return true;
        }

        

        

        return false;
    }
};