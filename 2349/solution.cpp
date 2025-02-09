class NumberContainers {
private:
    unordered_map<int, priority_queue<int, std::vector<int>, std::greater<int>>> containers;
    unordered_map<int, int> registrations;
public:
    NumberContainers() {
        containers.clear();
        registrations.clear();
    }
    
    void change(int index, int number) {
        unordered_map<int, priority_queue<int, std::vector<int>, std::greater<int>>>::iterator it = containers.find(number);
        priority_queue<int, std::vector<int>, std::greater<int>> *pq;
        if( it == containers.end()) {
            containers[number] = priority_queue<int, std::vector<int>, std::greater<int>>();
            pq = &containers[number];
        } else {
            pq = &(it->second);
        }

        pq->push(index);
        registrations[index] = number;
    }
    
    int find(int number) {
        unordered_map<int, priority_queue<int, std::vector<int>, std::greater<int>>>::iterator it = containers.find(number);
        if( it == containers.end()) {
            return -1;
        }

        priority_queue<int, std::vector<int>, std::greater<int>> &pq = it->second;
        int index;
        while( !pq.empty()) {
            index = pq.top();
            if(registrations[index] == number) {
                return index;
            }
            pq.pop();
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
