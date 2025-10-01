class Solution {
public:

    


    int romanToInt(string s) {

        int ans = 0;

        unordered_map<char, int> roman;

    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int i = 0;


        while( i < s.size()){

           char ch1 = s[i];
           char ch2 = s[i+1];
           if(roman[ch2] > roman[ch1]){
            ans +=  (roman[ch2] - roman[ch1]);
            i+=2;
           }else{
            ans += roman[ch1];
            i+=1;
           }


        }

        return ans;
        
    }
};