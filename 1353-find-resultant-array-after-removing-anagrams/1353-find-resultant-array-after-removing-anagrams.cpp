class Solution {
public:
    vector<string> removeAnagrams(vector<string>& word) {

        int n = word.size();

        vector<bool> vec(n, true);
        vector<string> words = word;

        sort(words[0].begin(), words[0].end());

        for (int i = 1; i < n; i++) {

            sort(words[i].begin(), words[i].end());

            int pre = i - 1;
            while (pre > 0 && vec[pre] == false) {
                pre--;
            }

            if (words[pre] == words[i]) {
                vec[i] = false;
            }
        }

        vector<string> result;

        for(int i=0; i<n; i++){
            if(vec[i] == true){
                result.push_back(word[i]);
            }
        }

        return result;
    }
};