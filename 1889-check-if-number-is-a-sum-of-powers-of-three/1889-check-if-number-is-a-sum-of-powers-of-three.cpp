class Solution {
public:
string num = "";
void fun(int n){
    if(n == 0) return;

    int x = n % 3;
    n /= 3;
    if(x < 0) n+=1;

     fun(n);
     num += to_string(x);

}
    bool checkPowersOfThree(int n) {


        fun(n);

        return !(num.find('2') != string::npos);
    }
};