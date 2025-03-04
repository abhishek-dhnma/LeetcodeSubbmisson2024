class Solution {
public:
    string num = "";
    void fun(int n){
        int r = 0;
        
        while(n != 0){

            r = n % 3;
            n /= 3;

            num += to_string(r); 
        }

    }

    bool checkPowersOfThree(int n) {
        fun(n);
        cout << num;
        return num.find('2') == string::npos;
    }
};