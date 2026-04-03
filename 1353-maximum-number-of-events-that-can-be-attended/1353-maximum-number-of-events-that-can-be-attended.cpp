class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end()); // based on startDay

        int start = events[0][0];

        int end = events[0][1];

        for(auto & e : events){
          end =  max(end, e[1] ); 
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        int maxEvents = 0;

        int i = 0;

        for(int d=start; d<=end; d++){
            
           
                while(i < events.size() && events[i][0] <= d ){
                    pq.push(events[i][1]);
                    i++;
                }

                while(!pq.empty() && pq.top() < d){
                    pq.pop();
                }


                if(!pq.empty()){
                    maxEvents++;
                    pq.pop();
                }
        }

        return maxEvents;

    }
};