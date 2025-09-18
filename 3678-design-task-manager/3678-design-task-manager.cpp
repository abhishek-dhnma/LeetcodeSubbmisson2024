struct Item {
    int priority;
    int taskId;
    int userId;
};


    struct cmp {

        bool operator()(const Item & a, const Item & b) {

            if (a.priority != b.priority)
                return a.priority < b.priority;
            if (a.taskId != b.taskId)
                return a.taskId < b.taskId;
            return a.userId < b.userId;
        }
    };

class TaskManager {
public:
    // max-heap


    priority_queue<Item, vector<Item>, cmp> pq;

    struct state{
        int priority;
        int userId;
        bool alive;
    };
    unordered_map<int, state> cur; // taskid - current state

    TaskManager(vector<vector<int>>& tasks) {

        for (int i = 0; i < tasks.size(); i++) {
            int priority = tasks[i][2], taskId = tasks[i][1], userId = tasks[i][0];

            cur[taskId] = {priority, userId, true};

            pq.push({priority,taskId,userId  });
        }
    }

    void add(int userId, int taskId, int priority) {

        cur[taskId] = {priority, userId,true};

        Item temp = {priority, taskId, userId};

        pq.push(temp);
    }

    void edit(int taskId, int newPriority) {

        auto it = cur.find(taskId);
        if(it == cur.end() || !it->second.alive) return;

        it->second.priority = newPriority;
        pq.push({newPriority, taskId, it->second.userId}); 

        
    }

    void rmv(int taskId) {

        auto it = cur.find(taskId);
        if(it == cur.end() || !it->second.alive) return;

        it->second.alive = false;
               
    }

    int execTop() {

        while(!pq.empty()){
            Item top = pq.top();
            auto it = cur.find(top.taskId);
            if(it == cur.end() || !it->second.alive){
                pq.pop();
                continue;
            }


            if(it->second.priority == top.priority && it->second.userId == top.userId){
                pq.pop();

                int userId = top.userId;
                it->second.alive = false;
                return userId;
            }else{
                pq.pop();
                continue;

            }
        }

        return -1;

        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */