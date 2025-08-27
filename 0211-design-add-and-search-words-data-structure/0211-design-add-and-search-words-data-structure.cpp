class TrieNode {

public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {

    TrieNode* root;

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {

        TrieNode* crawler = root;

        for (auto& ch : word) {
            int idx = ch - 'a';

            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = new TrieNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->isEnd = true;
    }

    bool explore(string & word, int i, TrieNode* crawler) {

        // BASE CASE

        if (i == word.size())
            return crawler->isEnd;

        char ch = word[i];

        if (ch == '.') {

            for (int j = 0; j < 26; j++) {

                if (crawler->children[j] == nullptr) {
                    continue;
                }

                bool status = explore(word, i + 1, crawler->children[j]);
                if (status == true) {
                    return true;
                }
            }
            return false;
        }

        int idx = ch - 'a';
        if (crawler->children[idx] == nullptr) {
            return false;
        }

        crawler = crawler->children[idx];
        return explore(word, i + 1, crawler);
    }

    bool search(string word) {
        TrieNode* crawler = root;

        return explore(word, 0, crawler);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */