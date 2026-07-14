class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        vector<vector<int>>t(hand.size()/groupSize);
        cout<<t.size()<<endl;
        sort(hand.rbegin(), hand.rend());
        for(auto it:hand)
        {
            bool check = false;
            for(auto &x: t){
                if(!x.empty() && x.size()<groupSize){
                    if(it == x.back()-1){
                    x.push_back(it);
                    check = true;
                    break;
                    }
                }
            }
            if(!check){
                bool f= false;
                for(auto &x:t)
                {
                    if(x.empty()){
                        x.push_back(it);
                        f = true;
                        break;
                    }
                }
                if(!f)return false;
            }
        }
        return true;
    }
};