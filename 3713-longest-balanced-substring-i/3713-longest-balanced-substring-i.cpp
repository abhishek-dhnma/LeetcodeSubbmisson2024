class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();

        int maxans = INT_MIN;
        
        for(int i=0; i<n; i++){
            unordered_map<char, int> mapp;
            for(int j=i; j<n; j++){

                char curchar = s[j];

                int val = mapp[curchar]++;
                int valid = true;
                
                for(auto e : mapp){
                    
                    if(e.second != mapp[curchar]){
                        
                    valid = false;
                    break;
                    }
                }

                if(valid){
                    
                        maxans = max(maxans, j-i+1);
                    
                }



            }


        }

        return maxans;
        
    }
};