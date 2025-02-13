#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<char> ans;
    bool brackets = false;
    bool encounter = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            brackets = true;
            continue;
        }
        if (s[i] == '.')
        {
            encounter = true;
            if (i + 1 < s.size())
            {
                ans.push_back(s[i + 1]);
            }
            else
            {
                ans.push_back('0');
                ans.push_back('0');
                break;
            }
            if (i + 2 < s.size())
            {
                ans.push_back(s[i + 2]);
                break;
            }
            else
            {
                ans.push_back('0');
                break;
            }
        }
        else
        {
            ans.push_back(s[i]);
        }
    }
    vector<char> finalans;
    reverse(ans.begin(), ans.end());
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i];
    cout << endl;
    if (encounter)
    {
        finalans.push_back(ans[0]);
        finalans.push_back(ans[1]);
        finalans.push_back('.');
        int count = 0;
        for (int i = 2; i < ans.size(); i++)
        {
            if (count == 3)
            {
                finalans.push_back(',');
                count = 0;
            }
            count++;
            finalans.push_back(ans[i]);
        }
    }
    else
    {
        finalans.push_back('0');
        finalans.push_back('0');
        finalans.push_back('.');
        int count = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (count == 3)
            {
                finalans.push_back(',');
                count = 0;
            }
            finalans.push_back(ans[i]);
            count++;
        }
    }
    reverse(finalans.begin(), finalans.end());
    if (!brackets)
    {
        cout << "$";
        for (int i = 0; i < finalans.size(); i++)
            cout << finalans[i];
        cout << endl;
    }
    else
    {
        cout << "($";
        for (int i = 0; i < finalans.size(); i++)
            cout << finalans[i];
        cout << ")";
        cout << endl;
    }
    return 0;
}