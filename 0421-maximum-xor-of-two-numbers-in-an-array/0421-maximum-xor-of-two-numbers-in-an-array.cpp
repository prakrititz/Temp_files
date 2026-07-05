class Solution {
public:
    struct Node{
    vector<Node*>a;
    bool f;
    Node(){
    a.assign(2, nullptr);
    f = false;
    }  
};
struct Trie{
    Node* root;
    Trie()
    {
        root = new Node();
    }
    void insert(string s){
        Node* curr = root;
        for(int i = 0;i<s.size();i++)
        {
            int id = 0;
            if(s[i]=='1')id = 1;
            if(curr->a[id]==NULL)
            {
                curr->a[id] = new Node();
            }
            curr = curr->a[id];
        }
        curr->f = true;
    }
    int maxi (string s)
    {
        int ans = 0;
        int bit = 31;
        Node *curr = root;
        for(int i = 0;i < s.size();i++)
        {
            int id = 0;
            if(s[i]=='1')id = 1;
            if(id==0 && curr->a[1]!=NULL)
            {
                ans += 1<<bit;
                curr = curr->a[1];
            }
            else if(id==1 && curr->a[0]!=NULL)
            {
                ans += 1<<bit;
                curr= curr->a[0];
            }
            else if(id==1 && curr->a[1]!=NULL)
            {
                curr = curr->a[1];
            }
            else if(id == 0 && curr->a[0]!=NULL)
            {
                curr = curr->a[0];
            }
            bit--;
        }
        return ans;
    }
};

string to_s(int x)
{
    string ans = "";
    for(int i = 31; i >= 0; i--)
        ans += ((x >> i) & 1) + '0';
    return ans;
}

int findMaximumXOR(vector<int>& nums) {
    Trie t;
    for(auto it:nums)
    {
        t.insert(to_s(it));
    }
    int ans = INT_MIN;
    for(auto it:nums)ans = max(ans, t.maxi(to_s(it)));
    return ans;
}
};