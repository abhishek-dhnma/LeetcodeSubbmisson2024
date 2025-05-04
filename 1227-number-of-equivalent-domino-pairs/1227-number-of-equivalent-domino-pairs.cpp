class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        map<pair<int, int>, int> mp;
        int ans = 0;

        for (auto & d : dominoes) {
            if (d[0] > d[1]) {
                swap(d[0],d[1]);
            }

            mp[{d[0], d[1]}]++;
        }

        

        for(auto & it : mp){
            int freq = it.second;

            ans += (freq * (freq-1)/2);
             
        }

        return ans;
    }
};