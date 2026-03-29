class EventManager {

public:

    set<pair<int, int>>  pq;
    unordered_map<int, int > mapp;
    
    EventManager(vector<vector<int>>& events) {
        for(const auto& e : events){
            int v = e[0];
            int p = e[1];
            pq.insert({-p,v});
            mapp[v] = -p;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(mapp.count(eventId)){

            int oldp = mapp[eventId];

            pq.erase({oldp, eventId});

            pq.insert({-newPriority, eventId});

            mapp[eventId] = -newPriority;
           
        }
    }
    
    int pollHighest() {

        if(pq.empty()){
            return -1;
        }


        auto [p, v] = *pq.begin();
        pq.erase(pq.begin());
        mapp.erase(v);
        return v;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */