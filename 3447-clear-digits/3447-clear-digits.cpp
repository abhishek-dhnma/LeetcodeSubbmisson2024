class Solution {
public:
    string clearDigits(string s) {

        stack<char> stk;
        int n = s.size();

        for(int i=0; i<n; i++){ // O(N)
            if(isdigit(s[i])){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }

        string ans = "";

        while(!stk.empty()){ //O(N)

            char c = stk.top();

            ans += c;
            stk.pop();

        }
        reverse(ans.begin(), ans.end()); // O(log N)

        return ans;
    
        
    }
};