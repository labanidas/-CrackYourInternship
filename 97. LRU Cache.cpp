class LRUCache {
public:
    list<int> ll;
    unordered_map<int, int> mp;
    unordered_map < int, list<int>::iterator > address;
    int capacity, size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        ll.erase(address[key]);

        ll.push_front(key);
        address[key] = ll.begin();

        return mp[key];
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            ll.erase(address[key]);
            ll.push_front(key);
            address[key] = ll.begin();
            mp[key] = value;
        } else {
            if (size == capacity) {
                mp.erase(ll.back());
                address.erase(ll.back());
                ll.pop_back();
                size--;
            }
            mp[key] = value;
            ll.push_front(key);
            address[key] = ll.begin();
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
