class Solution {
public:
    bool isAnagram(string s, string t) {

        // TC : O(n * log n)
        // SC : O(1)

        if(s.size() != t.size()) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(auto & c : s ){
            map1[c]++;
        }

        for(auto & c : t ){
            map2[c]++;
        }

        for(auto & c : s){
            if(map1[c] != map2[c]) return false;
        }
        
        return true;
    }
};