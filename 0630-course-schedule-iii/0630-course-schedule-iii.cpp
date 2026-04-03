class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        // Sort courses by deadline (earliest deadline first)
        // Greedy basis: always try to fit courses with tighter deadlines first
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        sort(courses.begin(), courses.end(), cmp);

        // Max-heap stores durations of currently selected courses
        // We want O(log n) access to the longest course so we can swap it out
        priority_queue<int> pq;

        int totalDay = 0; // tracks cumulative time spent so far

        for (auto& course : courses) {
            int duration = course[0];
            int deadline = course[1];

            // Tentatively take this course
            totalDay += duration;
            pq.push(duration);

            // If we've blown past the deadline, drop the heaviest course
            // This keeps the same number of courses but frees up the most time
            // (count doesn't decrease because we added before checking)
            if (totalDay > deadline) {
                totalDay -= pq.top(); // remove longest duration
                pq.pop();
            }
            // If totalDay <= deadline: course fits, keep it as-is
        }

        // Every element remaining in the heap = one valid completed course
        return pq.size();
    }
};