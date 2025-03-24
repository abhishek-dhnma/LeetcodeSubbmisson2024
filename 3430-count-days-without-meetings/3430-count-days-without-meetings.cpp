class Solution {
public:

    int mergeOverlap(vector<vector<int>>& arr){
        if (arr.empty()) return 0;

        int resIdx = 0; 

    for (int i = 1; i < arr.size(); i++) {
      
        if (arr[resIdx][1] >= arr[i][0])           
            arr[resIdx][1] = max(arr[resIdx][1], arr[i][1]);

        else {            
            resIdx++;
            arr[resIdx] = arr[i];
        }
    }
    arr.resize(resIdx + 1);
    return (resIdx + 1);

    }

    int countDays(int days, vector<vector<int>>& arr) {

        sort(arr.begin(), arr.end());

        int newSize = mergeOverlap(arr);

        int ans = 0, lastEnd = 0;

        for (int i = 0; i < newSize; i++) {

            // If the interval starts after 'days', stop counting
        if( arr[i][0] > days ){
            break;
        }
        // Count free days between last end and current start

        if(arr[i][0] > lastEnd +1){
            ans += (arr[i][0] - lastEnd - 1); 
        }

        // Update lastEnd but cap it at 'days'
        lastEnd = min(days, arr[i][1]);

        // If lastEnd reaches 'days', no need to continue
            if (lastEnd == days) break;
        
        }

        // If lastEnd is still less than days, add remaining free days
        if (lastEnd < days) {
            ans += (days - lastEnd);
        }

        return ans;
        
    }
};