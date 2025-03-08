class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        //Sliding Window
        int whiteCount = 0;
        int n = blocks.size();
        int ans = INT_MAX;

        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W') {
                whiteCount++;
            }

        }


        ans = whiteCount;

        for(int i=k ; i<n ; i++){

            if( blocks[i-k] == 'W' ) whiteCount--;
            if(blocks[i] == 'W' ) whiteCount++;
            
            ans = min(ans, whiteCount);
            
        } 

        return ans;
        
    }
};