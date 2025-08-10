class Solution {
public:
    bool isAnagram(string s, string t) {

        // TC : O(n * log n)
        // SC : O(2N)

        if(s.size() != t.size()) return false;

        vector<int> map1(26,0);
        vector<int> map2(26,0);

        for(auto & c : s ){
            map1[c - 'a']++;
        }

        for(auto & c : t ){
            map2[c - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(map1[i] != map2[i])return false;
        }
        
        return true;
    }
};