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
        void insert(int n){
            string s = to_s(n);
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
        string to_s(int x)
        {
            string ans = "";
            for(int i = 31; i >= 0; i--)
                ans += ((x >> i) & 1) + '0';
            return ans;
        }
        int maxi (int a)
        {
            string s= to_s(a);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        int m = queries.size();
        vector<int>ans(m);
        sort(nums.begin(), nums.end());
        vector<vector<int>>temp;
        for(int i = 0;i<m;i++)
        {
            temp.push_back({queries[i][1], queries[i][0], i});
        }
        sort(temp.begin(), temp.end());
        int i = 0;
        for(auto it:temp)
        {
            int m = it[0];
            int id = it[2];
            int val = it[1];
            while(i<nums.size() && nums[i]<=m)
            {
                t.insert(nums[i]);
                i++;
            }
            if(i==0)ans[id]= -1;
            else ans[id] = t.maxi(val);
        }
        return ans;
    }
};