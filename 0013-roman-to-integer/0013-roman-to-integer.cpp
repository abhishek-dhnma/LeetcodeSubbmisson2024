class Solution {
public:

    unordered_map<char, int> roman;

    int romanToInt(string s) {

        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;


        // main logic

        int i = 0;
        int n = s.size();

        int ans = 0;


        while( i <n){

            char ch1 = s[i];
            char ch2 = s[i+1];


            if( roman[ch1] < roman[ch2]){

            ans += ( roman[ch2] - roman[ch1] );
            i+=2;

            }else {

                ans +=  roman[ch1];
                i+=1;
            }


        }

        return ans;
        
    }
};

