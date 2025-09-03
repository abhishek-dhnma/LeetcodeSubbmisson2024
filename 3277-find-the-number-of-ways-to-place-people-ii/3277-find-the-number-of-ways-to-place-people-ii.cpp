class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        auto lamba = [](const vector<int>& point1, const vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }

            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lamba);

        int count = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {

            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;

            for (int j = i + 1; j < n; j++) {

                int x2 = points[j][0];
                int y2 = points[j][1];

                // check is points valid pairs

                if(x1 <= x2 && y1 >= y2){
                    if (maxY < y2) {
                    maxY = y2;
                    count++;
                }
                }

                
            }
        }

        return count;
    }
};