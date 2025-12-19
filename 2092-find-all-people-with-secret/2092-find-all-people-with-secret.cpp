class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {


             vector<bool> people(n, false);

            map<int,
                          vector<pair<int, int>>>
                mp;
            
            for(auto & m : meetings){
                
                int x = m[0];
                int y = m[1];
                int t = m[2];

                mp[t].push_back({x,y});

            }

            // at t  = 0
            people[0] = people[firstPerson] = true;


            // start your time
            

           for (auto &[t, meetingsAtT] : mp) {

    unordered_map<int, vector<int>> g;
    unordered_set<int> nodes;

    for (auto &[x, y] : meetingsAtT) {
        g[x].push_back(y);
        g[y].push_back(x);
        nodes.insert(x);
        nodes.insert(y);
    }

    unordered_set<int> visited;

    for (int start : nodes) {
        if (visited.count(start)) continue;

        queue<int> q;
        vector<int> component;
        bool hasSecret = false;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            component.push_back(u);
            if (people[u]) hasSecret = true;

            for (int v : g[u]) {
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }

        if (hasSecret) {
            for (int p : component)
                people[p] = true;
        }
    }
}



            vector<int> ans;

            for(int i=0; i<n; i++){
                if(people[i]) ans.push_back(i);
            }


            return ans;

    }
};