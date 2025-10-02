class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int bottleDrank = numBottles;
        int emptyBottle = numBottles;

        while(emptyBottle >= numExchange){

            emptyBottle -= numExchange;
            bottleDrank++;
            emptyBottle++;
            numExchange++;
            


        }

        return bottleDrank;
        
    }
};