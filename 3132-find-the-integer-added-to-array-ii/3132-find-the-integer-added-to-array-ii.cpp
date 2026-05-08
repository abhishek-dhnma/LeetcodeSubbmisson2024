class Solution {
public:
    int minimumAddedInteger(vector<int>& n1, vector<int>& n2) {

       
    sort(begin(n1), end(n1));
    sort(begin(n2), end(n2));
    for (int i = 2; i > 0; --i) {
        int skip = i;
        for (int j = i + 1; skip < 3 && j - skip < n2.size(); ++j)
            skip += n2[j - skip] - n1[j] != n2[0] - n1[i];
        if (skip < 3)
            return n2[0] - n1[i];
    }
    return n2[0] - n1[0];

        
    }
};