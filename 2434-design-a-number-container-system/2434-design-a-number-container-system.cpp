class NumberContainers {
public:

    unordered_map<int, int> container;
    unordered_map<int, set<int>> helper;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if(container.count(index)){
            int prenum = container[index];
            helper[prenum].erase(index);
            if(helper[prenum].empty()){
                helper.erase(prenum);
            }
        }
        container[index] = number;
        helper[number].insert(index);
    }
    
    int find(int number) {

        if(helper.count(number)){
            return *helper[number].begin();
        }

        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */