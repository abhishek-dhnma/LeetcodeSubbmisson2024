class Solution {
public:
    string clearDigits(string s) {

        int n = s.size();

        if(n == 1) return s;

        for(int i=0; i<n; i++){

            if(isdigit(s[i])) {
                if(i >= 1){
                s.erase(i-1,2);
                i=0;
                n = s.size();
            }
            cout << s << " ";
        }
        }
        //cout << s ;
        return s;
        
    }
};