#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<string>> res;
    unordered_map<string, int> mp; // Stores shortest transformation level

private:
    void dfs(string word, vector<string> &path, string &beginWord)
    {
        if (word == beginWord)
        {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (int i = 0; i < word.size(); i++)
        {
            string temp = word;
            for (char j = 'a'; j <= 'z'; j++)
            {
                temp[i] = j;
                if (mp.find(temp) != mp.end() && mp[temp] == mp[word] - 1) // Valid previous step
                {
                    path.push_back(temp);
                    dfs(temp, path, beginWord);
                    path.pop_back();
                }
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) // If endWord is not in wordList, return empty result
            return {};

        mp[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> usedInLevel;
        bool found = false;
        while (!q.empty() && !found)
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                string w = q.front();
                int level = mp[w];
                q.pop();

                for (int j = 0; j < w.size(); j++)
                {
                    string temp = w;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp[j] = ch;
                        if (wordSet.count(temp))
                        {
                            if (temp == endWord)
                                found = true; 

                            if (mp.find(temp) == mp.end())
                            {
                                q.push(temp);
                                mp[temp] = level + 1;
                                usedInLevel.insert(temp);
                            }
                        }
                    }
                }
            }

            for (const auto &word : usedInLevel)
                wordSet.erase(word);
            usedInLevel.clear();
        }

        if (!found)
            return {};

        vector<string> path = {endWord};
        dfs(endWord, path, beginWord);
        return res;
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution solution;
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);

    cout << "Word Ladders:\n";
    for (const auto &path : result)
    {
        for (const auto &word : path)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
