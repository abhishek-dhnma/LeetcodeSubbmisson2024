class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // freq map
        unordered_map<int, int> freq;

        for(auto & n : nums){

            freq[n]++;
        }

        // queue -> data structure

        priority_queue< pair<int, int> > que;

        for(auto &  [n , f]  : freq){

            que.push(  make_pair(f, n)   );


        }

        // queue give me k most frequent elements

        vector<int> ans;


        while( k-- && !que.empty()){

            // (f,n)
        
        ans.push_back(que.top().second);

        que.pop();

        }

        return ans;



        
    }
};