/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (23.28%)
 * Total Accepted:    246K
 * Total Submissions: 1.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
private:
    struct KVPair {
        int k, v;
        KVPair(int key, int value) : k(key), v(value) {}
    };
    int _capacity;
    list<KVPair> used_record;
    unordered_map<int, list<KVPair>::iterator> data;

public:
    LRUCache(int capacity) : _capacity(capacity) { }
    
    int get(int key) {
        if(data.find(key) == data.end())
            return -1;

        list<KVPair>::iterator pos = data[key];
        KVPair pair = *pos;

        used_record.erase(pos);
        used_record.push_front(pair);
        data[key] = used_record.begin();

        return pair.v;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            data[key]->v = value;
            return;
        }

        used_record.emplace_front(key, value);
        data[key] = used_record.begin();

        if(used_record.size() > _capacity){
            data.erase(used_record.back().k);
            used_record.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
