/*

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

*/

struct DLNode
{
    int key;
    int val;
    DLNode* prev;
    DLNode* next;
    DLNode(int x = -1,int y = -1): key(x),val(y),prev(NULL),next(NULL){}
};

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        m_head = new DLNode();
        m_tail = new DLNode();
        m_head->next = m_tail;
        m_head->prev = NULL;
        m_tail->next = NULL;
        m_tail->prev = m_head;
    }

    // @return an integer
    int get(int key)
    {
        if (m_cache.find(key) != m_cache.end())
        {
            // key found
            DLNode* tnode = m_cache[key];
            move_front(tnode);
            return tnode->val;
        }
        else return -1;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value)
    {
        if (m_cache.find(key) != m_cache.end())
        {
            // key found
            DLNode* tnode = m_cache[key];
            tnode->val = value;
            move_front(tnode);
            return;
        }

        // key not found
        if (m_cache.size() >= m_capacity)
        {
            DLNode* back = m_tail->prev;
            back->prev->next = m_tail;
            m_tail->prev = back->prev;
            back->prev = NULL;
            back->next = NULL;
            m_cache.erase(back->key);
        }

        DLNode* tnode = new DLNode(key,value);
        put_front(tnode);
        m_cache[key] = tnode;
    }


private:
    DLNode* m_head;
    DLNode* m_tail;
    int     m_capacity;
    unordered_map<int, DLNode*> m_cache;

private:
    void move_front(DLNode* tnode)
    {
        tnode->next->prev = tnode->prev;
        tnode->prev->next = tnode->next;
        tnode->prev = m_head;
        tnode->next = m_head->next;
        m_head->next->prev = tnode;
        m_head->next = tnode;
    }

    void put_front(DLNode* tnode)
    {
        tnode->prev = m_head;
        tnode->next = m_head->next;
        m_head->next->prev = tnode;
        m_head->next = tnode;
    }
};
