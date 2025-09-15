class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        vector<int> alpha(26, 0);


        for(auto & bl : brokenLetters){
            alpha[bl - 'a']++;
        }

        int i = 0,words = 0;

        bool isTypable = true;

        while(i < text.size()){

            if(text[i] == ' ' ){
                if(isTypable){
                    words++;
                }
                isTypable = true;
            }else if(alpha[text[i] - 'a'] == 1){
                isTypable = false;
            }
            i++;

        }

        if(isTypable){
            words++;
        }

        return words;
        
    }
};