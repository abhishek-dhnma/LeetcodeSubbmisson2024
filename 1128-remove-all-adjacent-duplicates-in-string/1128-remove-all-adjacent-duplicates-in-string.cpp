class Solution {
public:
    string removeDuplicates(string s) {

        string ans = "";

        // you can also use stack 

        stack<char> st;

        for(auto & ch : s){

            if( !st.empty() && st.top() == ch){

                // equal
                
                st.pop();

            }else{

                // not equal

                st.push(ch);
            }


        }

        while(!st.empty()){

            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());


        return ans;

        
        
    }
};