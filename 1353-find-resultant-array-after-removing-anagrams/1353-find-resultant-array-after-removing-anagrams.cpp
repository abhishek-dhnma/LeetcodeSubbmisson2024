class Solution {
public:
    vector<string> removeAnagrams(vector<string>& word) {

        int n = word.size();

        vector<string> result;

        vector<string> ans;

        vector<string> words = word;

        

        sort(words[0].begin(), words[0].end()); 
    
        result.push_back(words[0]);
        ans.push_back(word[0]);
        for (int i = 1; i < n; i++) { 

            sort(words[i].begin(), words[i].end()); 



            if (result.back() != words[i]) {
                result.push_back(words[i]);
                ans.push_back(word[i]);
            } 
        }

        return ans;
    }
};