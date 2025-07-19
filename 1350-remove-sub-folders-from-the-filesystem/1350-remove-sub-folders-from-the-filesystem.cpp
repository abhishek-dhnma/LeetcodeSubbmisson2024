class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        unordered_set<string> fldr(folder.begin(), folder.end());

        vector<string> ans;

        for (int i = 0; i < folder.size(); i++) {

            string currfolder = folder[i];

            bool isSub = false;

            while (true) {

                size_t position = currfolder.find_last_of('/');
                if (position == 0) break;  // reached root level like "/a"

                currfolder = currfolder.substr(0, position);

                if (fldr.find(currfolder) != fldr.end()) {
                    isSub = true;
                    break;
                }
            }

            if (!isSub) {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};