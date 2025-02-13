#include <bits/stdc++.h>
using namespace std;
bool isTaxi(const string &s)
{
    return s[0] == s[1] && s[1] == s[3] && s[3] == s[4] && s[4] == s[6] && s[6] == s[7];
}
bool isPizza(const string &s)
{
    return s[0] > s[1] && s[1] > s[3] && s[3] > s[4] && s[4] > s[6] && s[6] > s[7];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> names(n);
    unordered_map<string, int> taxiCount, pizzaCount, girlCount;

    for (int i = 0; i < n; ++i)
    {
        int si;
        string name;
        cin >> si >> name;
        names[i] = name;

        for (int j = 0; j < si; ++j)
        {
            string number;
            cin >> number;

            if (isTaxi(number))
            {
                taxiCount[name]++;
            }
            else if (isPizza(number))
            {
                pizzaCount[name]++;
            }
            else
            {
                girlCount[name]++;
            }
        }
    }

    int maxTaxi = 0, maxPizza = 0, maxGirl = 0;
    for (const auto &entry : taxiCount)
        maxTaxi = max(maxTaxi, entry.second);
    for (const auto &entry : pizzaCount)
        maxPizza = max(maxPizza, entry.second);
    for (const auto &entry : girlCount)
        maxGirl = max(maxGirl, entry.second);

    auto printResult = [&](const string &msg, const unordered_map<string, int> &countMap, int maxValue)
    {
        cout << msg;
        bool first = true;
        for (const auto &name : names)
        {
            if (countMap.at(name) == maxValue)
            {
                if (!first)
                    cout << ", ";
                cout << name;
                first = false;
            }
        }
        cout << ".\n";
    };

    cout << "If you want to call a taxi, you should call: ";
    bool first = true;
    for (const auto &name : names)
    {
        if (taxiCount[name] == maxTaxi)
        {
            if (!first)
                cout << ", ";
            cout << name;
            first = false;
        }
    }
    cout << ".\n";

    cout << "If you want to order a pizza, you should call: ";
    first = true;
    for (const auto &name : names)
    {
        if (pizzaCount[name] == maxPizza)
        {
            if (!first)
                cout << ", ";
            cout << name;
            first = false;
        }
    }
    cout << ".\n";

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    first = true;
    for (const auto &name : names)
    {
        if (girlCount[name] == maxGirl)
        {
            if (!first)
                cout << ", ";
            cout << name;
            first = false;
        }
    }
    cout << ".\n";

    return 0;
}
