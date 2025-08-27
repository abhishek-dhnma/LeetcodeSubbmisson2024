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

void insert(string& word, TrieNode* crawler) {

    for (int i = 0; i < word.size(); i++) {

        char ch = word[i];

        int idx = ch - 'a';

        if (crawler->children[idx] == nullptr) {
            crawler->children[idx] = new TrieNode();
        }

        crawler = crawler->children[idx];
    }

    crawler->isEnd = true;
}

void exploresuggestions(TrieNode* crawler, string build, vector<string> & sugg){

    if(sugg.size() == 3) return;

    if(crawler->isEnd){
        sugg.push_back(build);
    }

    for(int i=0; i<26; i++){

        if(crawler->children[i] != nullptr){
            char nextChar = 'a' + i;
            exploresuggestions(crawler->children[i], build + nextChar, sugg);
            if(sugg.size() == 3)return;// stop early
        }
    }

}

void search(string word, TrieNode* root, vector<string> & sugg){

        TrieNode* crawler = root;

    for(auto & ch : word){

        int idx = ch - 'a';

        if(crawler->children[idx] == nullptr){

            return ;
        }

        crawler = crawler->children[idx];


    }
    
    // here im at prefix node

    exploresuggestions(crawler, word, sugg);
     
}

class Solution {
public:
    TrieNode* root = new TrieNode();

    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        

        sort(products.begin(), products.end()); // ensures lexicographic order

        for (auto& p : products) {

            insert(p, root);
        }

        vector<vector<string>> ans;

        string prefix = "";

        for(auto & c : searchWord){

            prefix += c;

            vector<string> sugg;

            search(prefix, root, sugg);

            ans.push_back(sugg);
        }

        return ans;
    }
};