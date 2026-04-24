class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int number_of_dash = 0;
        int currmoves = 0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i] == '_') number_of_dash++;

            if(moves[i] == 'L') currmoves -= 1;
            if(moves[i] == 'R') currmoves += 1;
        }


        return abs(currmoves) + number_of_dash;
        
    }
};