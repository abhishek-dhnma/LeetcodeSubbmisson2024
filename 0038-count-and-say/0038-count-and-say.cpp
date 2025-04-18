class Solution {
public:
    string RLE(int i, int n, string out) {

        // BASE CASE
        if (i == n) {
            return out;
        }

       
            string temp = "";
            int count = 1;
            // Recursive Func
            for (int j = 1; j < out.size(); j++) {

                

                if (out[j] == out[j- 1]) {
                    count++;
                } else {
                    temp += to_string(count) + out[j-1];
                    count = 1;
                }
            }
            


        temp += to_string(count) + out.back();

        return RLE(i + 1, n, temp);
    }

    string countAndSay(int n) {

        return RLE(1, n, "1");
    }
};