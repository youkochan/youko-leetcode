/**
 * Design and implement a data structure for Least Recently Used (LRU) cache. 
 * It should support the following operations: get and set.
 * get(key) -  Get the value (will always be positive) of the key if the key exists in the cache, 
 * otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. 
 * When the cache reached its capacity, 
 * it should invalidate the least recently used item before inserting a new item.
 */

// 数据结构，表示CACHE的每一个块
class CacheEntry
{
public:
    int key;
    int value;
    CacheEntry(int k, int v) :key(k), value(v) {}
};

class LRUCache{
private:
    // 用于记录KEY值与CACHE元素之间的对应关系
    unordered_map<int, list<CacheEntry>::iterator> m_map;
    // 应一个LIST表示一个CACHE块
    list<CacheEntry> m_list;
    // 容量，超过容量时应该根据LRU方案淘汰CACHE块
    int m_capacity;
    
    // 将最近使用过的KEY移到最前
    void moveToHead(int key) {
        auto it = m_map[key];
        CacheEntry newItem(it->key, it->value);
        m_list.erase(it);
        m_list.push_front(newItem);
        m_map[key] = m_list.begin();
    }

public:
    LRUCache(int capacity) {
        this->m_capacity = capacity;
    }
    
    int get(int key) {
        if (m_map.find(key) == m_map.end())
            return -1;
        
        moveToHead(key);
        return m_map[key]->value;
    }
    
    void set(int key, int value) {
        // KEY值无缓存，判断是否需要淘汰最不常用的再更新CACHE
        if(m_map.find(key) == m_map.end()) {
            CacheEntry newItem(key, value);
            
            if(m_list.size() == m_capacity) {
                // 淘汰最不常用的缓存
                m_map.erase(m_list.back().key);
                m_list.pop_back();
            }
            
            // 往链表头部插入缓存
            m_list.push_front(newItem);
            m_map[key] = m_list.begin();
            return;
        }
        
        // KEY值有缓存，直接更新后移到头部
        m_map[key]->value = value;
        moveToHead(key);
    }
};