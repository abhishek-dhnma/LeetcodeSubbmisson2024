class Solution {
public:
    bool isValid(string word) {

        if (word.size() < 3)
            return false;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
        unordered_set<char> SpecialChar = {'@', '#', '$'};
        
        bool vowelsCount = false;
        bool consonantCount = false;

        for (auto& ch : word) {

            if (SpecialChar.count(ch)) {
                return false;
            }

            if (isalpha(ch)) {

                if (vowels.count(ch)) {
                    vowelsCount = true;

                } else {
                    consonantCount = true;
                }
            } 
        }


        return  vowelsCount && consonantCount;
    }
};