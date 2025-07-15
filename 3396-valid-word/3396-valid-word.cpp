class Solution {
public:
    bool isValid(string word) {

        if (word.size() < 3)
            return false;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
        unordered_set<char> SpecialChar = {'@', '#', '$'};

        bool containsDigit = false;
        bool vowelsCount = false;
        bool consonantCount = false;

        for (auto& ch : word) {

            if (SpecialChar.count(ch)) {
                return false;
            }

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {

                if (vowels.count(ch)) {
                    vowelsCount = true;

                } else {
                    consonantCount = true;
                }
            } else

                if (ch >= '0' && ch <= '9') {
                containsDigit = true;
            }
        }

        cout << containsDigit << " " << vowelsCount << " " << consonantCount;

        return  vowelsCount && consonantCount;
    }
};