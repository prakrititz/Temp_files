class Solution {
public:
    int minAddToMakeValid(string s) {
        int extra_pop = 0;
        stack<int>st;
        for(auto it:s)
        {
            if(it=='(')
            {
                st.push(1);
            }
            else{
                if(st.empty())extra_pop++;
                else st.pop();
            }
        }
        return st.size()+extra_pop;
    }
};