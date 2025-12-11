#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // edge-case: if no buildings
        if (buildings.empty()) return 0;

        // store extremes as requested: "x_k" -> (minY, maxY), "y_k" -> (minX, maxX)
        unordered_map<string, pair<int,int>> extremeSave;

        // maps for O(n) min/max accumulation
        unordered_map<int, pair<int,int>> x_to_yminmax; // x -> (minY, maxY)
        unordered_map<int, pair<int,int>> y_to_xminmax; // y -> (minX, maxX)

        // initialize maps
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // x -> minY, maxY
            if (!x_to_yminmax.count(x)) x_to_yminmax[x] = {y, y};
            else {
                auto &pr = x_to_yminmax[x];
                pr.first = min(pr.first, y);
                pr.second = max(pr.second, y);
            }

            // y -> minX, maxX
            if (!y_to_xminmax.count(y)) y_to_xminmax[y] = {x, x};
            else {
                auto &pr = y_to_xminmax[y];
                pr.first = min(pr.first, x);
                pr.second = max(pr.second, x);
            }
        }

        // move into extremeSave with the requested keys
        for (auto &p : x_to_yminmax) {
            int x = p.first;
            int minY = p.second.first;
            int maxY = p.second.second;
            extremeSave["x_" + to_string(x)] = {minY, maxY};
        }
        for (auto &p : y_to_xminmax) {
            int y = p.first;
            int minX = p.second.first;
            int maxX = p.second.second;
            extremeSave["y_" + to_string(y)] = {minX, maxX};
        }

        // count covered buildings
        int count = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto xrangeIt = extremeSave.find("x_" + to_string(x));
            auto yrangeIt = extremeSave.find("y_" + to_string(y));
            if (xrangeIt == extremeSave.end() || yrangeIt == extremeSave.end()) continue;

            pair<int,int> yrange = xrangeIt->second; // actually minY,maxY for this x
            pair<int,int> xrange = yrangeIt->second; // actually minX,maxX for this y

            // check: building strictly inside both ranges (not on boundary)
            if (yrange.first < y && yrange.second > y && xrange.first < x && xrange.second > x) {
                count++;
            }
        }

        return count;
    }
};
