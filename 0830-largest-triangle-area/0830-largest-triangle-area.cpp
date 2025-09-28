class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {

        int n =  points.size();

        double maxAns = 0.0;

        for(int i=0; i<=n-3; i++){
            for(int j=i+1; j<=n-2; j++){
                for(int k=j+1; k<=n-1; k++){

                    double x1 = points[i][0]; 
                    double y1 = points[i][1];
                    double x2 = points[j][0];
                    double y2 = points[j][1];
                    double x3 = points[k][0];
                    double y3 = points[k][1];

                    //double shoelace_formula =  abs(  (x1 * (y2-y3)) + (x2 * (y3 - y1 )) + (x3 * (y1 - y2)) ) * 0.5;

                    double a = hypot(x2-x1, y2-y1);
                    double b = hypot(x2-x3, y2-y3);
                    double c = hypot(x1-x3, y1-y3);


                    double s = 0.5 *(a+b+c);

                    double heron_formula = sqrt(s * (s-a) * (s-b) * (s-c));
                    
                    maxAns = max(maxAns,heron_formula );


                }
            }
        }


        return maxAns;
        
    }
};