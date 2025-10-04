class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();

        int m = t.size();

        map<char, vector<int> > mp;


        // insert all t into map
        for(int i=0; i<m; i++){

            mp[ t[i] ].push_back(i);
        }


        // logic 


        int previndex = -1;

        // iterating s here every s char into map
        for(int i = 0; i<n; i++){


            char ch = s[i];

            // not present

            if(mp.find(ch) == mp.end()){

                return false;

            }


            // if present - in map

            vector<int> idx = mp[ch];

            // next larger value 

            auto it = upper_bound(idx.begin(), idx.end(), previndex);

            if( it ==  idx.end()) {
// same logic but differn way 

                return false;
            }

            previndex = *it;

            // true
        }

// s is subseq of t
        return true;



        
    }
};