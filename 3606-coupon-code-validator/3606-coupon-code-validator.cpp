class Solution {
public:


    bool isValidCode(string code){


        if(code.empty()){
            return false;
        }

        bool check;     

        for(auto & c : code){
            if( ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c &&  c <= '9') || ( '_' == c)){
                check = true;
            }else {
                check = false;
                break;
            }
        }

        return check;

    }

    bool isValidBzLine(string bxline){

        if(bxline == "electronics" || bxline == "grocery" || bxline == "pharmacy" || bxline == "restaurant" ){
            return true;
        }else {
            return false;
        }

    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        int n = code.size();

        vector<vector<string>> mp(4);

        // e = 0 
        // gro = 1
        // pha = 2
        // rest = 3

        for(int i=0; i<n; i++){


            string c = code[i];
            string bl = businessLine[i];

            if( !isActive[i] || !isValidCode(c) || !isValidBzLine(bl)){
                continue;
            }

            if(bl == "electronics"){

                mp[0].push_back(c);

            }else if(bl == "grocery"){

                mp[1].push_back(c);

            }else if(bl == "pharmacy"){

                mp[2].push_back(c);

            }else if(bl == "restaurant"){

                mp[3].push_back(c);

            }


        }

        // vector<string> ans;
        
        // for(int i=0; i<code.size(); i++){

        //     if( !code[i].empty() && isValidCode(code[i]) && isValidBzLine(businessLine[i]) && isActive[i]){
        //         ans.push_back(code[i]);
        //     }

        // }

        vector<string> ans;

        for(auto & vec : mp){

            sort(vec.begin(), vec.end());

            for(auto & s : vec ){

                ans.push_back(s);
            }

        }




        return ans;
    }
};