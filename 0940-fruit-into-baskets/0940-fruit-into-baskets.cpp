class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        if(n <= 2) return n;

        int i = 0;
        int j = 0;

        int maxVal = 0;
        int currWindowSize = 0;


        unordered_map<int, int> fruitCount;

        while (j < n) {

            fruitCount[fruits[j]]++;


                while (fruitCount.size() > 2) {
                    fruitCount[fruits[i]]--;

                    if (fruitCount[fruits[i]] == 0) {
                        fruitCount.erase(fruits[i]);
                    }
                    i++;
                }


            currWindowSize = j - i +1 ;
            maxVal = max(currWindowSize, maxVal);

            j++;
        }
        return maxVal;
    }
};