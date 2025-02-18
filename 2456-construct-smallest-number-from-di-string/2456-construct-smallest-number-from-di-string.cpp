class Solution {
public:
    string smallestNumber(string pattern) {
        

        int n = pattern.size();

        string num = "";

        stack<char> st;

        for(int i=0; i<=n; i++){
            st.push(i+1);

            if(i == n || pattern[i] == 'I'){
                while(!st.empty()){
                    num += to_string(st.top());
                    st.pop();
                }
            }


        }
        return num;
    }
};