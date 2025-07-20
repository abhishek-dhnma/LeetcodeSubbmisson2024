class Solution {
public:
    struct Node {
        string val;
        string subfolder;
        unordered_map<string, Node*> children;
    };

    Node* getNode(string val){
        Node* temp = new Node();
        temp->val = val;
        temp->subfolder = "";

        return temp;
    }

    void insert(Node* root, vector<string>& path){
        for(auto& folder : path){
            if(!root->children.count(folder)){
                root->children[folder] = getNode(folder);
            }

            root = root->children[folder];
        }
    }

    string populateNodes(Node* root, unordered_map<string, int>& subfolderMap){

        vector<pair<string, string>> subfolderPaths;
        for(auto &[childName, child] : root->children){
            string subfolderResult = populateNodes(child, subfolderMap);
            subfolderPaths.push_back({childName, subfolderResult});
        }

        sort(begin(subfolderPaths), end(subfolderPaths));

        string completePath = "";
        for(auto& [childrenName, childPath] : subfolderPaths){
            completePath += "(" + childrenName + childPath + ")";
        }
        root->subfolder = completePath;

        if(!completePath.empty()){
            subfolderMap[completePath]++;
        }

        return completePath;
    }


    void removeDuplicates(Node* root, unordered_map<string, int>& subfolderMap){
        for(auto it = root->children.begin(); it != root->children.end();){
            string childName = it->first;
            Node* child = it->second;

            if(!child->subfolder.empty() && subfolderMap[child->subfolder] >1){
                it = root->children.erase(it);
            }else{
                removeDuplicates(child, subfolderMap);
                it++;
            }
        }
    }


    void constructResult(Node* root, vector<string> path, vector<vector<string>> & result){
        for(auto & [childName, child] : root->children){
            path.push_back(childName);
            result.push_back(path);
            constructResult(child, path, result);
            path.pop_back();
        }
    }







    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = getNode("/");

        for(auto& path : paths){
            insert(root, path);
        }

        unordered_map<string, int> subfolderMap;
        populateNodes(root, subfolderMap);

        removeDuplicates(root, subfolderMap);

        vector<vector<string>> result;

        vector<string> path;
        constructResult(root, path, result);

        return result;
        
    }
};