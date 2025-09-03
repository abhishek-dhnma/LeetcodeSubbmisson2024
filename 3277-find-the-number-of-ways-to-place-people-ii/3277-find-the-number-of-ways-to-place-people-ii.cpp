class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Time Complexity: O(N log N) for sorting + O(N²) for nested loops
        // Space Complexity: O(1) excluding input storage

        // Custom sort: x in ascending order, if x equal then y in descending order
        auto lamba = [](const vector<int>& point1, const vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1]; // Higher y first for same x
            }
            return point1[0] < point2[0]; // Smaller x first
        };

        // Sort points to process left-to-right and top-to-bottom
        sort(points.begin(), points.end(), lamba); // O(N log N)

        int count = 0; // Track total valid pairs
        int n = points.size(); // Total number of points

        // Loop through each point as starting point
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0]; // x-coordinate of point i
            int y1 = points[i][1]; // y-coordinate of point i

            int maxY = INT_MIN; // Track max y of valid paired points

            // Check all points after i for valid pairs
            for (int j = i + 1; j < n; j++) { // O(N²) for nested loops
                int x2 = points[j][0]; // x-coordinate of point j
                int y2 = points[j][1]; // y-coordinate of point j

                // Valid pair if x1 <= x2 and y1 >= y2
                if (x1 <= x2 && y1 >= y2) {
                    // Ensure no point lies between y1 and y2
                    if (maxY < y2) {
                        maxY = y2; // Update max y seen so far
                        count++; // Increment pair count
                    }
                }
            }
        }

        return count; // Return total number of valid pairs
    }
};