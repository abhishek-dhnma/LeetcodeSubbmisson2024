class Solution {
public:
    bool isValid(string word) {

         if (word.size() < 3)
            return false;

        // Disallow special characters
        regex specialCharsPattern("[@#$]");
        if (regex_search(word, specialCharsPattern))
            return false;

        // At least one vowel (case-insensitive)
        regex vowelPattern("[aeiouAEIOU]");
        if (!regex_search(word, vowelPattern))
            return false;

        // At least one consonant (case-insensitive)
        regex consonantPattern("[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]");
        if (!regex_search(word, consonantPattern))
            return false;

        return true;
    }
};