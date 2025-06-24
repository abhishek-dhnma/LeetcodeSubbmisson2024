class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int res_idx = 0;

        int i = 0;

        while(i < n){

            // main logic

            char curr_ch = chars[i];
            int count = 0;

            while(i<n && chars[i] == curr_ch ){
                count++;
                i++;
            }

            chars[res_idx] = curr_ch;
            res_idx++;
            
            if(count > 1){

                string c_str = to_string(count);

                for(char & ch : c_str){
                    chars[res_idx] = ch;
                    res_idx++;
                }

            }

        }

        return res_idx;


        
    }
};