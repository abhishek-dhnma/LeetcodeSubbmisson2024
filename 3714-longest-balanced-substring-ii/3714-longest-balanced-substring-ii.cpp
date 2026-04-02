class Solution {
public:

    int helper(string s, char x, char y){

        int n = s.size();
        unordered_map<int, int> diffMap;

        int countx = 0;
        int county = 0;

        int maxL = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] != x && s[i] != y){
                diffMap.clear();
                countx = 0;
                county = 0;
                continue;
            }
            
            if(s[i] == x){
                countx++;
            }

            if(s[i] == y){
                county++;
            }

            if(countx == county){
               maxL = max(maxL, countx + county);
            }else{
                if(diffMap.count(countx-county)){
                    int idx = diffMap[countx - county];
                    maxL = max(maxL, i - idx);

                }else {
                    diffMap[countx-county] = i; 
                }
            }

        }
        return maxL;



    }

    int longestBalanced(string s) {

        int n = s.size();

        // case 1 - single character - a or b or c - any
        int i=0;
        int maxL = 0;
        for(int j=0; j <n ;j++){
           if(s[i] != s[j]){
            i = j;
           }
           maxL = max(maxL, j - i + 1);
        }

        // case 2 - two distinct characters 

        // a-b
        maxL = max(maxL, helper(s, 'a', 'b'));
       

        // b-c
        maxL = max(maxL, helper(s, 'b', 'c'));


        // a-c
        maxL = max(maxL, helper(s, 'a', 'c'));



        // case 3 - all three characters - a,b,c
        int counta = 0;
        int countb = 0;
        int countc = 0;
        unordered_map<string, int> diffMap;

        for(int i=0; i<n; i++){

            if(s[i] == 'a') counta++;
            if(s[i] == 'b') countb++;
            if(s[i] == 'c') countc++;

            if(counta == countb && counta == countc){
                maxL = max(maxL, counta+countb+countc);
            }

            int diffab = counta - countb;
            int diffac = counta - countc;

            string key = to_string(diffab) + "_" + to_string(diffac);

            if(diffMap.count(key)){
                maxL = max(maxL, i - diffMap[key]);
            }else{
                diffMap[key] = i;
            }



        }

        return maxL;
        
    }
};