class Trie {
public:
    struct Node{
        vector<Node*>a;
        bool flag;
            Node() {
            a.assign(26, nullptr);
            flag = false;
        }
    };
    Node* root;
    Trie() {
         root = new Node();       
    }
    
    void insert(string word) {
        int n = word.size();
        Node *curr = root;
        for(int i = 0;i<n;i++)
        {
            char x = word[i];
            if(curr->a[x-'a']==NULL)
            {
                curr->a[x-'a'] = new Node();
            }
            curr = curr->a[x-'a'];
        }
        curr->flag = true;
    }
    
    bool search(string word) {
        int n = word.size();
        Node * curr = root;
        for(int i = 0;i<n;i++)
        {
            char x = word[i];
            if(curr->a[x-'a']==NULL)
            {
                return false;
            }
            curr = curr->a[x-'a'];
        }
        if(curr->flag == true)return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node * curr = root;
        for(int i = 0;i<n;i++)
        {
            char x = prefix[i];
            if(curr->a[x-'a']==NULL)
            {
                return false;
            }
            curr = curr->a[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
