/*
 * Two maps, one ordered and the other one unordered
 * use of lower_bound(k): the last one before value k
 */
class TimeMap {
private:
    unordered_map<string, map<int, string, greater<int>>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it1 = m.find(key);
        if (it1 != m.end()) {
            auto it2 = it1->second.lower_bound(timestamp);    
            if (it2 != it1->second.end()) {
                return it2->second;
            }
        }
        return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */