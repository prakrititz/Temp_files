class Solution {
public:
    bool check(vector<int>& stations, int k, double dist) {
        int used = 0;
        for(int i =1;i<stations.size();i++)
        {
            double gap =  stations[i] - stations[i-1];
            if(gap<=dist)
            {
                continue;
            }
            int needed = floor((gap/dist));
            used += needed;
        }
        return used<=k;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        double l = 0;
        double r = 0;
        for (int i = 1; i < stations.size(); i++)
            r = max(r, (double)(stations[i] - stations[i - 1]));

        while (r - l > 1e-6) {
            double mid = (l + r) / 2.0;

            if (check(stations, k, mid))
                r = mid;
            else
                l = mid;
        }

        return r;
    }
};