class Solution {
public:
    bool halvesAreAlike(string s) {

        int n = s.size();

        int i = 0;
        int j = n/2;

        int Lc = 0, Rc = 0;

        // SET

        unordered_set<char> st;

        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        // a e i o u A E I O U


        while( i<n/2 && j<n){
            // MAIN LOGIC

                // left side
            if( st.find(s[i]) != st.end()) Lc++;

            // right side
             if( st.find(s[j]) != st.end()) Rc++;

             i++;
             j++;
        }

        return Lc == Rc;
        
    }
};