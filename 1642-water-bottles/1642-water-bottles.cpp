class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int emptyBottles = 0;
        int newBottles = 0;
        int comsumeBottles = numBottles;

    while(numBottles >= numExchange){
        emptyBottles = ((numBottles)%numExchange);
        newBottles = (numBottles-emptyBottles)/numExchange;
        comsumeBottles += newBottles;
        numBottles =  newBottles + emptyBottles;
    }
        
        return comsumeBottles;


        
    }
};