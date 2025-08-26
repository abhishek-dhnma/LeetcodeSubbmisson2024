class Trie {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];
    };

    TrieNode* getNode() {
        TrieNode * newNode = new TrieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    TrieNode* root;

    Trie() { root = getNode(); }

    void insert(string word) {

        TrieNode* crawler = root;

        for (auto& ch : word) {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }

    bool search(string word) {

        TrieNode* crawler = root;

        for (auto& ch : word) {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) {
                return false;
            }

            crawler = crawler->children[idx];
        }

        if (crawler != NULL && crawler->isEndOfWord == true) {
            return true;
        }

        return false;
    }

    bool startsWith(string prefix) {

        TrieNode* crawler = root;
        int i = 0;

        for (; i<prefix.size() ;i++) {
            char ch = prefix[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) {
                return false;
            }

            crawler = crawler->children[idx];
        }

        if (i == prefix.size()) {
            return true;
        }

        return false;


    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */