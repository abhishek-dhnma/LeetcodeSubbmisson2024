class Solution {
public:

    long long recurion(int i, vector<vector<int>>& q, int n, vector<long long>& memo){

        if(i >= n){
            return 0;
        }

        if(memo[i] != -1){
            return memo[i];
        }

        int ptr = q[i][0];
        int bp = q[i][1];


        long long take = ptr + recurion(i + bp + 1, q, n, memo);
        long long skip = recurion(i+1,q,n,memo);

        return  memo[i] = max(take, skip);

    }

    long long mostPoints(vector<vector<int>>& q) {

        int n = q.size();

        long long ans = INT_MIN;

        vector<long long> memo(n, -1);


        return recurion(0,q,n,memo);
        
    }
};