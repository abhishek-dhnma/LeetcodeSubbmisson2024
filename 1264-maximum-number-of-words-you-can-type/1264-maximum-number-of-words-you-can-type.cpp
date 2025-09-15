class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        vector<int> alpha(26, 0);


        for(auto & bl : brokenLetters){
            alpha[bl - 'a']++;
        }

        int i = 0,words = 0;

        while(i < text.size()){

            bool isTypable = true;

            while(i < text.size() && text[i] != ' ' ){
                if(alpha[text[i] - 'a']) isTypable = false;
                i++;
            }

            if(isTypable){
                words++;
            }

            i++;

        }

        return words;
        
    }
};