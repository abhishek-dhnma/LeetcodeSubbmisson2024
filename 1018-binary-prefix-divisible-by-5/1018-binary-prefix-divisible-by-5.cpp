class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int n = nums.size();
        vector<bool> ans(n);

        // 'remainder' will store the current prefix's remainder modulo 5.
        // Why do we store only remainder?
        // -------------------------------------------------------------
        // Divisibility rule:
        // A number is divisible by 5 <=> its remainder modulo 5 is 0.
        //
        // So instead of building the full prefix number (which becomes huge),
        // we track only the remainder of the prefix when divided by 5.
        //
        // This works because modulo arithmetic is compatible with addition
        // and multiplication:
        //   (a * 2 + b) % 5 = ((a % 5) * 2 + b) % 5
        //
        // That means: knowing only 'remainder' is enough to compute
        // the next prefix remainder perfectly.
        // -------------------------------------------------------------
        int remainder = 0;


        // Loop through each bit in the binary input
        for (int i = 0; i < n; i++) {

            // CORE IDEA:
            // A binary number grows like this:
            // ---------------------------------
            // If old number = X
            // and next bit = b (0 or 1)
            //
            // New number = X * 2 + b
            //
            // This is because appending a bit in binary is equivalent to
            // shifting left (multiply by 2) and then adding the new bit.
            //
            // Example:
            //   101 (5 in decimal)
            //   append 1 -> 1011
            //   computation: 5*2 + 1 = 11
            // ---------------------------------

            // Instead of storing the full prefix number,
            // we compute only its remainder modulo 5.
            //
            // Math property allowing this:
            // (X * 2 + b) % 5 = ((X % 5) * 2 + b) % 5
            //
            // So we store X % 5, call it 'remainder',
            // and update it every iteration.
            remainder = (remainder * 2 + nums[i]) % 5;

            // If the remainder is 0, the prefix is divisible by 5
            ans[i] = (remainder == 0);
        }

        return ans;
    }
};
