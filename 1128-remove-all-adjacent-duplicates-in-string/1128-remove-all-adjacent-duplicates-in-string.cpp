class Solution {
public:
    string removeDuplicates(string s) {

        string ans = "";

        for(auto & ch :  s){

            if( !ans.empty()  && ans.back() == ch){
                // equal
                ans.pop_back();
                
            }else {

                //not equal

                ans.push_back(ch);


            }


        }

        return ans;
        
    }
};