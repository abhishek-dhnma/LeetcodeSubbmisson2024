class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // map - it will help me to count the freq
        // heap - max heap - get the most freq elemt in const O(1)

        unordered_map<int, int> freq;

        //1 - 3;

        for(auto & n : nums){

            freq[n]++;
        }

        // insert these int que 

        priority_queue< pair<int, int> > que; // max heap

        for(auto & [n, f] : freq ){


            que.push(make_pair(f, n));


        }

        vector<int> ans;


        while( k-- && !que.empty()){

            pair<int, int> x = que.top();

            ans.push_back(x.second);

            que.pop();

        }

        return ans;





        
    }
};