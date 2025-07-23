class Solution {
public:
    int maximumGain(string s, int x, int y) {

        int result= 0;

        char ch1,ch3;
        char ch2, ch4;

        int mx_val = max(x,y);
        int mn_val = min(x,y);

        
        if(x > y){
            ch1 = 'a';
            ch2 = 'b';
        }else{
            ch1 = 'b';
            ch2 = 'a';
        }


        
        int n = s.size();

        //max nikalunga
        int i = 0; 
        for(; i < n-1; i++){

            while(s[i] == ch1 && s[i+1] == ch2){
                s.erase(i , 2);
                result += mx_val;
                i = max(0, i-2);
                n -= 2;
            }

 
        }

        // min niklaunga

       if(ch1 == 'a' && ch2 == 'b'){
         ch1 = 'b';
         ch2 = 'a';
       }else{
        ch1 = 'a';
        ch2 = 'b';
       }


        for(int i=0; i < n-1 ; i++){

            while(s[i] == ch1 && s[i+1] == ch2){
                s.erase(i , 2);
                result += mn_val;
                i = max(0, i-2);
                n -= 2;
            }

        }



        //result

        return result;
        
    }
};