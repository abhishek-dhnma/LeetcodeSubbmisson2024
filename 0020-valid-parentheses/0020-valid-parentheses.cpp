class Solution {
public:
    bool isValid(string s) {

        // stack

        stack<char> stk;

        for (auto& ch : s) {

            // open - push stack
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            }
            // close braces - check top if matching or not
            else if (ch == '}' || ch == ']' || ch == ')') {

                // edge case
                if(stk.empty()){
                    return false;
                }

                char top = stk.top();
                stk.pop();

                if ((top == '(' && ch != ')') || (top == '{' && ch != '}') ||
                    (top == '[' && ch != ']')) {
                    return false;
                }
            }
        }


        return stk.empty();
    }
};