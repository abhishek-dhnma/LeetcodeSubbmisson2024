class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue <long, vector<long>, greater<long>> pq(begin(nums), end(nums)); // heapify - logn()

        long result = 0;


        while( !pq.empty() &&  pq.top() < k){
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            
            pq.push( ( x*2 ) + y );

            result++;
        }

        return result;
    }
};