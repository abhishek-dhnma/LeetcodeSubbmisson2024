class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        sort(s1.begin(), s1.end());

        int s = s1.size();
        int n = s2.size();

        for(int i=0; i<=n-s; i++){

            string str = s2.substr(i, s);

            sort(str.begin(), str.end());

            if(str == s1){
                return true;
            }



        }

        return false;

        
        
    }
};