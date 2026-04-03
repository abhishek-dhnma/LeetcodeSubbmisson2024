class Solution {
public:

    int scheduleCourse(vector<vector<int>>& courses) {

        auto cmp =  [](const vector<int>& a, const vector<int>& b){

            return a[1] < b[1];

        };

        sort(courses.begin(), courses.end(), cmp);

        priority_queue<int> pq; // max heap

        int totalday = 0;
        for(auto& course : courses){
            int duration = course[0];
            int deadline = course[1];

            totalday += duration;
            pq.push(duration);

            if(totalday > deadline){
                totalday -= pq.top();
                pq.pop();
            }
          
        }

        return pq.size();

        
    }
};