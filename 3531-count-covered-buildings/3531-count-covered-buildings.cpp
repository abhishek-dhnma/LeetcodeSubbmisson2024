#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // edge-case: if no buildings
        if (buildings.empty()) return 0;

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


        // count covered buildings
        int count = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            // guaranteed to exist since we populated from buildings, but checking is cheap
            const auto &yrange = x_to_yminmax.at(x); // (minY, maxY)
            const auto &xrange = y_to_xminmax.at(y); // (minX, maxX)
            // check: building strictly inside both ranges (not on boundary)
            if (yrange.first < y && yrange.second > y && xrange.first < x && xrange.second > x) {
                count++;
            }
        }

        return count;
    }
};
