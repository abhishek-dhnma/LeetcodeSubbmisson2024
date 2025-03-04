class Solution {
public:
    

    void fun(int n, string& num){
        while(n != 0){
            num = to_string( n % 3) + num;
            n /= 3;
        }
    }

    bool checkPowersOfThree(int n) {
        string num = "";
        fun(n, num);
        return num.find('2') == string::npos;
    }
};