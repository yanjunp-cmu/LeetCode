/*
    key thing to take away: use a doubly linked list and hash map to maintain an LRU Cache
    double linked list stores key-value pairs
    hash map stores key and list iterators for fast lookups


    list.splice() place element to specified position
*/
class LRUCache {
private:
    int LRUcap;
    list<pair<int, int> > LRU_dl;
    // LRU hashmap, key is the desired key, value is the iterator of the element inside the doubly linked list
    unordered_map<int, list<pair<int, int>>::iterator> LRU_map;
public:
    LRUCache(int capacity) {
        LRUcap = capacity;
    }
    
    int get(int key) {
        // return the value
        auto found_itr = LRU_map.find(key);
        
        if (found_itr == LRU_map.end()) 
            return -1; // did not find the key
        
        // move to the front when found
        LRU_dl.splice(LRU_dl.begin(), LRU_dl, found_itr->second);
        
        return found_itr->second->second;
    }
    
    void put(int key, int value) {
        auto found_itr = LRU_map.find(key);
        
        if (found_itr != LRU_map.end()){ // key exists
            // move to the front when found
            LRU_dl.splice(LRU_dl.begin(), LRU_dl, found_itr->second);
            // update node value
            found_itr->second->second = value;
            return;
        }
        
        if (LRU_map.size() == LRUcap){ // capacity reached
            int key_to_del = LRU_dl.back().first;
            LRU_dl.pop_back();
            LRU_map.erase(key_to_del);
        }
        LRU_dl.emplace_front(key, value); // create new node in front
        LRU_map[key] = LRU_dl.begin(); // create new pair of key and node
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */