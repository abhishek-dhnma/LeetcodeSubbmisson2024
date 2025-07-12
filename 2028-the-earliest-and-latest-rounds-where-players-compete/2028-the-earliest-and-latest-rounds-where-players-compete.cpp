class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {

        int left = firstPlayer;
        int right = secondPlayer;

        if(left == n - right + 1){
            return {1,1};
        }

        if(left > n - right + 1){
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        int minRound = n;
        int maxRound = 1;
        int nextRoundPlayerCount = (n+1)/2;

        if(right <= nextRoundPlayerCount){

            //CASE 1 : Both player at the same side
            int countLeft = left - 1;
            int midCount = right - left -1;
            
            for(int sleft =0; sleft <= countLeft; sleft++){
                for(int sMid =0; sMid <= midCount; sMid++){
                    int pos1 = sleft + 1;
                    int pos2 = pos1 + sMid + 1;

                    vector<int> tempResult = earliestAndLatest(nextRoundPlayerCount, pos1, pos2);

                    minRound = min(tempResult[0] + 1, minRound);
                    maxRound = max(tempResult[1] + 1, maxRound);
                }
            }
        }else {
            // CASE 2 : both on opposite side
            int fightsRight = n - right + 1;
            int countleft = left -1;
            int midCount = fightsRight - left -1;
            int remainingMidCount = right - fightsRight - 1;

            for(int sleft =0; sleft <= countleft; sleft++){
                for(int sMid =0; sMid <= midCount; sMid++){
                    int pos1 = sleft + 1;
                    int pos2 = pos1 + sMid +  (remainingMidCount+1)/2 +  1;

                    vector<int> tempResult = earliestAndLatest(nextRoundPlayerCount, pos1, pos2);

                    minRound = min(tempResult[0] + 1, minRound);
                    maxRound = max(tempResult[1] + 1, maxRound);
                }
            }

        }

        return {minRound, maxRound};
        
    }
};