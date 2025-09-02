class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        int count = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            // point A
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n; j++) {

                if (i == j) {
                    continue;
                }

                // point B
                int x2 = points[j][0];
                int y2 = points[j][1];

                // check points(A,B) are valid or not

                if (x1 <= x2 && y1 >= y2) {

                    bool isInside = false;

                    for (int k = 0; k < n; k++) {

                        // apart from A and B
                        // Check other points if they lie inside or not
                        if (k == i || k == j) {
                            continue;
                        }

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if (x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                            isInside = true;
                            break;
                        }
                    }

                    if (!isInside) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
