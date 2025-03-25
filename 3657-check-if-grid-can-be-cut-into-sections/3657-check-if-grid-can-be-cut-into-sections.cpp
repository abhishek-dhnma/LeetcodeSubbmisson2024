class Solution {

vector<vector<int>> merge(vector<vector<int>>& rectangles){
     int x = rectangles.size();

        sort(rectangles.begin(), rectangles.end());

        vector<vector<int>> result;

        result.push_back(rectangles[0]);

        for(int i=1; i<x; i++){
            if(rectangles[i][0] <  result.back()[1]){
                result.back()[1] = max(result.back()[1], rectangles[i][1]);
                
            }else{
                result.push_back(rectangles[i]);
            }
        }
 
        return result;
}

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {


        vector<vector<int>> hor;
        vector<vector<int>> ver;

        for(auto& coord : rectangles){

            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];

            hor.push_back({x1, x2});
            ver.push_back({y1, y2});


        }



       vector<vector<int>> result1 = merge(hor);
       vector<vector<int>> result2 = merge(ver);

       return result1.size() >= 3 || result2.size() >= 3;

        
    }
}; 