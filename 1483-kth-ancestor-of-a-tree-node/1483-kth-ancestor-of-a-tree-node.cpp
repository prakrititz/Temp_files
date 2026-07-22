class TreeAncestor {
public:
    int log = 0;
    vector<vector<int>>u;
    TreeAncestor(int n, vector<int>& parent) {
        int x = 1;
        while(x<=n){
            log++;
            x*=2;
        }
        u.assign(n, vector<int>(log, -1));
        for(int i = 0;i<n;i++)
        {
            u[i][0] = parent[i];
        }
        for(int j = 1;j<log;j++)
        {
            for(int i = 1;i<n;i++)
            {
                if(u[i][j-1]==-1)u[i][j] = -1;
                else u[i][j] = u[u[i][j-1]][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        int current = node;
        int i = 0;
        while(k)
        {
            if(k%2){
                current = u[current][i];
            }
            if(current == -1)break;
            i++;
            k/=2;
        }
        return current;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */