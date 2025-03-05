class Solution {
public:
    long long coloredCells(int n) {

        // pattern observation

        int t= 1;
        long long cell = 1;

        while( t <= n){

            cell += (4 * (t-1));
            t++;
        }

        return cell;
        
    }
};