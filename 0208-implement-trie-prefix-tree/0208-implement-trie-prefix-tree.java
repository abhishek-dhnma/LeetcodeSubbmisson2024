class TrieNode {
    TrieNode [] children = new TrieNode[26];
    boolean isEnd = false;
}
class Trie {

    TrieNode root;

    public Trie() {
        root = new TrieNode();
        
    }
    
    public void insert(String word) {

        TrieNode crawler =  root;

        for(int i=0; i<word.length(); i++){

            char ch = word.charAt(i);

            int idx = ch - 'a';

            if(crawler.children[idx] == null){

                crawler.children[idx] = new TrieNode();

            }

            crawler = crawler.children[idx];

        }

        crawler.isEnd = true;




        
    }
    
    public boolean search(String word) {

        TrieNode crawler =  root;

        for(int i=0; i<word.length(); i++){

            char ch = word.charAt(i);

            int idx = ch - 'a';

            if(crawler.children[idx] == null){

                return false;

            }

            crawler = crawler.children[idx];

        }

        return crawler.isEnd ;
        
    }
    
    public boolean startsWith(String prefix) {

        TrieNode crawler =  root;

        int i=0;

        for(; i<prefix.length(); i++){

            char ch = prefix.charAt(i);

            int idx = ch - 'a';

            if(crawler.children[idx] == null){

                return false;

            }

            crawler = crawler.children[idx];

        }

        if(i == prefix.length()){
            return true;
        }

        return  false;
        
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */