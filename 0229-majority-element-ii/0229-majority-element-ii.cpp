class Solution {
public:
vector<int> boor_moyer(vector<int>& a, int k)
{
    int n = a.size();

    vector<int> candidate(k - 1);
    vector<int> cnt(k - 1, 0);

    // Find potential candidates
    for (int x : a)
    {
        bool done = false;

        // Case 1: Already a candidate
        for (int i = 0; i < k - 1; i++)
        {
            if (cnt[i] > 0 && candidate[i] == x)
            {
                cnt[i]++;
                done = true;
                break;
            }
        }

        if (done) continue;

        // Case 2: Empty slot
        for (int i = 0; i < k - 1; i++)
        {
            if (cnt[i] == 0)
            {
                candidate[i] = x;
                cnt[i] = 1;
                done = true;
                break;
            }
        }

        if (done) continue;

        // Case 3: Decrement all counters
        for (int i = 0; i < k - 1; i++)
            cnt[i]--;
    }

    // Verify candidates
    fill(cnt.begin(), cnt.end(), 0);

    for (int x : a)
    {
        for (int i = 0; i < k - 1; i++)
        {
            if (candidate[i] == x)
                cnt[i]++;
        }
    }

    vector<int> ans;

    for (int i = 0; i < k - 1; i++)
    {
        if (cnt[i] > n / k)
        {
            bool exists = false;
            for (int y : ans)
            {
                if (y == candidate[i])
                {
                    exists = true;
                    break;
                }
            }
            if (!exists)
                ans.push_back(candidate[i]);
        }
    }

    return ans;
}
    vector<int> majorityElement(vector<int>& a) {
        return boor_moyer(a, 3);
    }
};