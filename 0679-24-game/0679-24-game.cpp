class Solution {
public:

    double epsilon = 0.0006;

    bool solve(vector<double> & nums){

        if(nums.size() == 1){
            return abs(nums[0] - 24.0) <= epsilon;
        }







        for(int i = 0; i< nums.size(); i++ ){
            for(int j = 0; j<nums.size(); j++){

                if(i==j) continue;
                vector<double> temp;



                for(int k=0; k<nums.size(); k++){
                    if(k != i && k != j ){
                        temp.push_back(nums[k]);
                    }
                }

                double a = nums[i];
                double b = nums[j];

                // options 
                vector<double> possVal = {a+b, a-b, b-a, a*b};

                if(abs(b) > 0.0){
                    possVal.push_back(a/b);
                }

                if(abs(a) > 0.0){
                    possVal.push_back(b/a);
                }

                
                for(double val : possVal){
                    temp.push_back(val); // do
                    if(solve(temp) == true){ // explore
                        return true;
                    }
                    temp.pop_back(); // undo 

                    // AKA BACKTRACKING
                }




            }
        }

        return false;

    }

    bool judgePoint24(vector<int>& cards) {

        int n = cards.size();

        vector<double> nums;

        for(int i=0; i<n; i++){
            nums.push_back( 1.0 * cards[i]);
        }

        return solve(nums);
        
    }
};