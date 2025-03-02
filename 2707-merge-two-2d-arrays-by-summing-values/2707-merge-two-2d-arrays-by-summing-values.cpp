class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        //USING POINTER 

        vector<vector<int>> res;

         auto ptr1 = nums1.begin(), ptr2 = nums2.begin();  // Using iterators (pointers)

        while (ptr1 != nums1.end() && ptr2 != nums2.end()) {
            if ((*ptr1)[0] == (*ptr2)[0]) {  
                res.push_back({(*ptr1)[0], (*ptr1)[1] + (*ptr2)[1]});
                ptr1++; ptr2++;  // Move both pointers
            } 
            else if ((*ptr1)[0] < (*ptr2)[0]) {
                res.push_back(*ptr1);
                ptr1++;  // Move pointer for nums1
            } 
            else {
                res.push_back(*ptr2);
                ptr2++;  // Move pointer for nums2
            }
        }

        // Add remaining elements from nums1
        while (ptr1 != nums1.end()) {
            res.push_back(*ptr1);
            ptr1++;
        }

        // Add remaining elements from nums2
        while (ptr2 != nums2.end()) {
            res.push_back(*ptr2);
            ptr2++;
        }

        return res;
        
    }
};