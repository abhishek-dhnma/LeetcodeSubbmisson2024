class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {

        int m = words.size();
        vector<int> ans;

        auto lamda  = [x](char ch){
            return (ch == x);
        };


        for(int i=0; i<m; i++){

            if( any_of(begin(words[i]), end(words[i]), lamda) == true){
                 ans.push_back(i);
            }

        }

        
        return ans;
        
    }
};