class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int l = 0;
        while (l < n && s[l] == 'L') l++;        // leading Ls never collide

        int r = n - 1;
        while (r >= 0 && s[r] == 'R') r--;      // trailing Rs never collide

        if (l > r) return 0;                    // nothing in the middle

        int collisions = 0;
        for (int i = l; i <= r; ++i) {
            if (s[i] != 'S') collisions++;      // every R or L here will collide at least once
        }

        return collisions;
    }
};
