class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        // optimal approach :

        if(buildings.size() < 5){
            return 0;
        }

            // Final result → for each "x_k" or "y_k" store (min, max)
    unordered_map<string, pair<int,int>> extremeSave;

    // ------------- GROUP BY X → get min & max Y for each X -------------
    unordered_map<int, vector<pair<int,int>>> xmp;

    for (auto &b : buildings) {
        int x = b[0], y = b[1];
        xmp[x].push_back({x, y});
    }

    for (auto &entry : xmp) {
        int x = entry.first;
        auto &v = entry.second;

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second < b.second;    // sort by Y
        });

        int minY = v.front().second;
        int maxY = v.back().second;

        extremeSave["x_" + to_string(x)] = {minY, maxY};
    }

    // ------------- GROUP BY Y → get min & max X for each Y -------------
    unordered_map<int, vector<pair<int,int>>> ymp;

    for (auto &b : buildings) {
        int x = b[0], y = b[1];
        ymp[y].push_back({x, y});
    }

    for (auto &entry : ymp) {
        int y = entry.first;
        auto &v = entry.second;

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.first < b.first;    // sort by X
        });

        int minX = v.front().first;
        int maxX = v.back().first;

        extremeSave["y_" + to_string(y)] = {minX, maxX};
    }


        int count = 0;
        for(auto & b : buildings){
            int x = b[0], y = b[1];

            auto xrangeIt = extremeSave.find("x_" + to_string(x));
            auto yrangeIt = extremeSave.find("y_" + to_string(y));
            if (xrangeIt == extremeSave.end() || yrangeIt == extremeSave.end()) continue;

            pair<int,int> yrange = xrangeIt->second; // actually minY,maxY for this x
            pair<int,int> xrange = yrangeIt->second; // actually minX,maxX for this y

            // check: building strictly inside both ranges (not on boundary)

            if(xrange.first < x && xrange.second > x && yrange.first < y && yrange.second > y){
                count++;
            }


        }

        return count;

    }
};