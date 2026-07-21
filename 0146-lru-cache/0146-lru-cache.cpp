struct Node{
    int key, val;
    Node* next;
    Node* prev;
    Node(int x, int y)
    {
        key = x;
        val = y;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    Node*root;
    Node*tail;
    unordered_map<int, Node*>mp;
    int K = 0;
    LRUCache(int capacity) {
        K = capacity;
        root = NULL;
        tail = NULL; 
    }
    int get(int key) {
        if(root && root->key == key)return  root->val;
        if(tail && tail->key == key){
            tail->next = root;
            root->prev = tail;
            if(tail->prev){
                tail = tail->prev;
                tail->next = NULL;
            }
            root = root->prev; 
            return root->val;
        }
        if(mp.find(key)!=mp.end())
        {
            Node* node = mp[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = root;
            root->prev = node;
            node->prev = NULL;
            root = node;
            return root->val;
        }
        else {
            return -1;
        }
    }
    void put(int key, int value) {
        Node* x; 
        if(mp.find(key)!=mp.end())
        {   
            x = mp[key];
            x->val = value;
            if(root->key==key)return;
            if(tail->key==key)
            {
                tail->next = root;
                root->prev = tail;
                if(tail->prev){
                    tail = tail->prev;
                    tail->next = NULL;
                }
                root = root->prev; 
                return;
            }
            Node* x = mp[key];
            x->prev->next = x->next;
            x->next->prev = x->prev;
            x->next = root;
            root->prev = x;
            x->prev = NULL;
            root = x;
            return;
        }
        x = new Node(key, value);
        if(mp.size()==K)
        {
            mp.erase(tail->key);
            Node* temp = tail;
            if(tail->prev){
                tail = tail->prev;
                tail->next = NULL;
            }
            else{
                root = NULL;
                tail = NULL;
            }
            delete(temp);
        }
        x->next = root;
        if(!root)
        {
            root  = x;
            tail  = x;
        }
        else{
            root->prev = x;
            root = x;
        } 
        mp[key] = x;
    }
};
