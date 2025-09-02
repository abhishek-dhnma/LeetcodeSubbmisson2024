class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {


        auto lamba = [](vector<int>& point1, vector<int> & point2){

            if(point1[0] == point2[0] ){
                return point1[1] > point2[1];
            }

            return point1[0] < point2[0];

        };

        sort(points.begin(), points.end(), lamba);

        int count = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            // point A
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;

            for (int j = i+1; j < n; j++) {



                // point B
                int x2 = points[j][0];
                int y2 = points[j][1];

                // check points(A,B) are valid or not


                if(y2 > y1){

                    continue;
                }

                if(y2 > maxY){
                    count++;
                    maxY =  y2;
                }
            }
        }

        return count;
    }
};
