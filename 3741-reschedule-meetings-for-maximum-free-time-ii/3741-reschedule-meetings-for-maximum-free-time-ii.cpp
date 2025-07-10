class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        vector<int> freeTimes;

        freeTimes.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); i++) {
            freeTimes.push_back(startTime[i] - endTime[i - 1]);
        }

        freeTimes.push_back(eventTime - endTime[endTime.size() - 1]);

        int sz = freeTimes.size();

        vector<int> maxRightFree(sz,0);
        vector<int> maxLeftFree(sz,0);

        for(int i = sz-2; i>=0; i--){
            maxRightFree[i] = max(maxRightFree[i+1], freeTimes[i+1]);
        }

        for(int i = 1; i < sz; i++){
            maxLeftFree[i] = max(maxLeftFree[i-1], freeTimes[i-1]);
        }

int result = 0;

for(int i =1; i<sz ;i++){
    int currEventTime = endTime[i-1]  - startTime[i-1];
// case 1 
    if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])){
        result = max(result, freeTimes[i-1] + currEventTime + freeTimes[i]);

    }
    //case 2

    result = max(result, freeTimes[i-1] + freeTimes[i]);
}

return result;



        
    }
};