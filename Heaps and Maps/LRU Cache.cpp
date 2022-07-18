#include<list>
int capacity;
unordered_map<int, int> keyvalue;
unordered_map<int, std::list<int>::iterator> position;
list<int> cache;

LRUCache::LRUCache(int capacity) {
    ::capacity = capacity;
    position.clear();
    keyvalue.clear();
    cache.clear();
}

int LRUCache::get(int key) {
    if(keyvalue.find(key) == keyvalue.end())
        return -1;

    // move from previous position to lru position
    cache.erase(position[key]);
    cache.push_front(key);
    position[key] = cache.begin();
    return keyvalue[key];
}

void removeMostRecentUsed(){
    if(cache.size() > capacity){
        keyvalue.erase(keyvalue.find(cache.back()));
        position.erase(position.find(cache.back()));
        cache.pop_back();
    }
}

void LRUCache::set(int key, int value) {
    if(keyvalue.find(key) != keyvalue.end()){
        cache.erase(position[key]);
    }

    // remove from previous position
    cache.push_front(key);
    keyvalue[key] = value;
    position[key] = cache.begin();
    removeMostRecentUsed();
}