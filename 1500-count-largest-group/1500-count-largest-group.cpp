class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n != 0) {
            int last = n % 10;
            sum += last;
            n /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {

        unordered_map<int,int> groupCount;

        for (int i = 1; i <= n; i++) {
            int key = sumOfDigits(i);
            groupCount[key]++;
        }
        int maxCount =0, result =0;

        for(auto [key, count] : groupCount){
            if(count > maxCount){
                maxCount = count;
                result = 1;
            }else if(count == maxCount){
                result++;
            }
        }


        return result;
    }
};