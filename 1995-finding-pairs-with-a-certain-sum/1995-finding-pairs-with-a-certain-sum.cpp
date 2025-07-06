class FindSumPairs {
public:
    vector<int> _nums1, _nums2;
    unordered_map<int, int> freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        _nums1 = nums1;
        _nums2 = nums2;

        for(auto & num : nums2){
            freq[num]++;
        }
        
    }
    
    void add(int index, int val) {

        int oldVal = _nums2[index];
        freq[oldVal]--;

        if(freq[oldVal] == 0){
            freq.erase(oldVal);
        }

        _nums2[index] += val;
        freq[_nums2[index]]++;

    }
    
    int count(int tot) {

        //kadance Algo
        // efficient this code
        // two for loop se ho jayega kaam. 

        int cnt = 0;
/* // brute force
        for(int i=0; i< _nums1.size(); i++){
            for(int j=0; j< _nums2.size(); j++){
                if( _nums1[i] + _nums2[j] == tot){
                    cnt++;
                }
            }
        }*/



        for(auto & num : _nums1){
            int complement = tot - num;
            if(freq.count(complement)){
                cnt += freq[complement];
            }
        }

        return cnt;
    
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */