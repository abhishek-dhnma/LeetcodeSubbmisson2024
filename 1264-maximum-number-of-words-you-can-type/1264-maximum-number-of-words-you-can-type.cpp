class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        int n = brokenLetters.size();

        vector<int> alpha(26, 0);

        for (int i = 0; i < n; i++) {

            int idx = brokenLetters[i] - 'a';
            alpha[idx]++;
        }


        //----------------

        int words = 0;
        bool isTypable = true;
        int i = 0;

        while (i < text.size()) {

            isTypable = true;


            while(i < text.size() && text[i] != ' '){
                if(alpha[text[i] - 'a']) isTypable = false;
                i++;

            }

            if (isTypable) {
                words++;
            }

            i++;
        }

        return words;
    }
};