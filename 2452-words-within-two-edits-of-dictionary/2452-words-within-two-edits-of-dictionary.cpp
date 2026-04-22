class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {

        // brute force
        int n = queries.size();
        int m = dictionary.size();

        int l = queries[0].size();

        vector<string> ans;

        for (int i = 0; i < n; i++) {
            string qword = queries[i];

            for (int j = 0; j < m; j++) {
                string dword = dictionary[j];
                int count = 0;
                for (int k = 0; k < l; k++) {
                    if (qword[k] != dword[k]) {
                        count++;
                    }
                    if (count > 2) {
                        break;
                    }
                }

                if (count <= 2) {
                    ans.push_back(qword);
                    break;
                }
            }
        }

        return ans;
    }
};