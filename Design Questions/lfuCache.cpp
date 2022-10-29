/**
 * Imlement the LFUCache class:
 * LFUCache(int capacity) Initializes the object with the capacity of the data structure.
 * int get(int key) Gets the value of the key if the key exists in the cache.
 *  Otherwise, returns -1.
 * void put(int key, int value) Update the value of the key if present, or inserts the
 * key if not already present. When the cache reaches its capacity, it should invalidate
 * and remove the least frequently used key before inserting a new item. For this problem,
 * when there is a tie (i.e., two or more keys with the same frequency), the least recently
 * used key would be invalidated.
 *
 * Problem Statement: https://leetcode.com/problems/lfu-cache/
 */
class LFUCache {
public:
    int capacity;
    unordered_map<int, list<int>>freqKeyList;
    unordered_map<int, vector<int>>keyValueFreq;
    //value corresponding to key and freq corresponding to key
    unordered_map<int, list<int>::iterator>keyIterator;
    int minFreq;
    int sz;

    LFUCache(int capacity) {
        this->capacity = capacity;
        sz = 0;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyValueFreq.count(key))
            return -1;
        int value = keyValueFreq[key][0];
        int freq = keyValueFreq[key][1];
        freqKeyList[freq].erase(keyIterator[key]);
        freqKeyList[freq + 1].push_back(key);
        keyValueFreq[key][1]++;
        keyIterator[key] = --freqKeyList[freq + 1].end();
        while (!freqKeyList[minFreq].size()) {
            minFreq++;
        }
        return value;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        if (get(key) != -1) {
            keyValueFreq[key][0] = value;
            return;
        }
        if (sz == capacity) {
            //remove element from cache with min freq
            int keyToRemove = freqKeyList[minFreq].front();
            freqKeyList[minFreq].pop_front();
            keyValueFreq.erase(keyToRemove);
            keyIterator.erase(keyToRemove);
        }
        keyValueFreq[key] = {value, 1};
        freqKeyList[1].push_back(key);
        keyIterator[key] = --freqKeyList[1].end();
        minFreq = 1;
        if (sz < this->capacity) {
            sz++;;
        }
    }

};