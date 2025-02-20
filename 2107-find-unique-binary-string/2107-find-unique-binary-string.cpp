class Solution {
public:
    int binaryToDecimal(string s)
{
    bitset<32> bits(s);
    int number = bits.to_ulong();
    return number;
}

string toBinary(int n) {
    bitset<5> b(n);
    return b.to_string();
}

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        int size = 1 << n; // Efficient way to compute 2^n

        vector<bool> mp(size,false);

        for(const auto& str : nums){
            
            int nmbr = binaryToDecimal(str);

            mp[nmbr] = true;

        }

        string ans = "";

        for(int i=0; i<size; i++){
            if(!mp[i]){

                 bitset<16> b(i);
                ans=  b.to_string().substr(16-n);
                break;
                
            }
        }

        

        return ans;
        
    }
};