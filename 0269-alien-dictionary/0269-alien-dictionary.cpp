class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<int>>g(26);
        vector<int>indeg(26, 0);
        vector<int>p(26, 0);
        for(auto it:words)for(auto x:it)p[x-'a']++;
        int c = 0;
        for(auto it:p)if(it)c++;
        for(int i=0;i<words.size()-1;i++)
        {
            string a = words[i];
            bool f = true;
            string b = words[i+1];
            int len = min(a.size(), b.size());
            for(int j=0;j<len;j++)
            {
                if(a[j]!=b[j])
                {
                    g[a[j]-'a'].push_back(b[j]-'a');
                    indeg[b[j]-'a']++;
                    f = false;
                    break;
                }
            }
            if(f && a.size()>b.size())return "";
        }
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>vis(26, 0);
        for(int i = 0;i<26;i++)
        {
            if(indeg[i]==0 && p[i]!=0){
                pq.push(i);
                vis[i] = 1;
            }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            int u = pq.top();
            pq.pop();
            ans.push_back(u);
            for(auto it: g[u])
            {
                indeg[it]--;
                if(indeg[it]==0 && !vis[it])
                {
                    pq.push(it);
                    vis[it] = 1;
                } 
            }
        }
        if(ans.size()!=c)return "";
        string s = "";
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            s += char('a'+it);
        }
        return s;
    }
};