class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());  

        vector<int> v1;
        vector<int> v2;

        for(auto & n1 : s1){
            if(!s2.count(n1)){
                v1.push_back(n1);
            }
        }

        for(auto & n2 : s2){
            if(!s1.count(n2)){
                v2.push_back(n2);
            }
        }
        





        return {v1, v2};
        
    }
};