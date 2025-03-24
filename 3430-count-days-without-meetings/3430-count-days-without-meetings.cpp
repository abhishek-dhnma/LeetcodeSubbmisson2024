class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());


        int end = 0, start = 0, result = 0;;


        for(auto& meet : meetings){

            if(meet[0] > end){
                result += meet[0] - end - 1;
            }

        end = max(meet[1], end);

        }

        if(days > end){
            result +=( days - end);
        }

        return result;
        
    }
};