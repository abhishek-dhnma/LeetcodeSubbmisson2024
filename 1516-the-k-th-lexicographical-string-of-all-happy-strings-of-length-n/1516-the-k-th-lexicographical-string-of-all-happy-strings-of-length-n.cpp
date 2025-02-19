class Solution {
public:

    void generate(int n, int &k, string& current, string& result){

        if(current.size() == n){
            k--;
            if(k == 0){
                result = current;
            }
            return;
        }

        for(char ch = 'a'; ch<='c'; ch++){

            if(current.empty() || current.back() != ch){  // Ensure no adjacent chars are the same
                current.push_back(ch);
                generate(n, k, current, result);
                current.pop_back();

                if(!result.empty()) return;

            }
        }
    }

    string getHappyString(int n, int k) {

        string result = "";
        string current = "";
        generate(n, k, current, result);

       return result;
    }
};