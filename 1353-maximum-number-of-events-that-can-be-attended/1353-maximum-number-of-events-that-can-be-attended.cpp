class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        // Sort events by start day so we can process them in chronological order
        sort(events.begin(), events.end());

        // Find the range of days we need to simulate
        int start = events[0][0];
        int end = events[0][1];
        for(auto& e : events){
            end = max(end, e[1]);
        }

        // Min heap to always attend the event with the earliest deadline
        // This is the core greedy choice — pick what expires soonest
        priority_queue<int, vector<int>, greater<int>> pq;

        int maxEvents = 0;

        // Pointer to track which events have been added to the heap
        // Moves forward only — each event is added exactly once across all days
        int i = 0;

        // Simulate each day from first event start to last event end
        for(int d = start; d <= end; d++){

            // Add all events that have started on or before today
            // Their end days go into the min heap
            while(i < events.size() && events[i][0] <= d){
                pq.push(events[i][1]);
                i++;
            }

            // Remove events that have already expired (end day passed)
            // We can no longer attend these
            while(!pq.empty() && pq.top() < d){
                pq.pop();
            }

            // Attend the event with the earliest deadline (greedy pick)
            // One event per day — pop it so we don't attend it again
            if(!pq.empty()){
                maxEvents++;
                pq.pop();
            }
        }

        return maxEvents;
    }
};