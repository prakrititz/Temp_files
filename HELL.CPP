#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    int next[26];
    vector<int> word_ids;
    TrieNode() { fill(begin(next), end(next), -1); }
};

struct Solver
{
    int R, C;
    vector<vector<char>> board;
    vector<string> words;
    vector<TrieNode> trie;
    vector<char> visited;
    vector<int> found_flag;
    vector<string> found_words;

    Solver(int r = 0, int c = 0) : R(r), C(c) { trie.emplace_back(); }

    void insert_word(const string &w, int id)
    {
        int node = 0;
        for (char ch : w)
        {
            int idx = ch - 'a';
            if (trie[node].next[idx] == -1)
            {
                trie[node].next[idx] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[idx];
        }
        trie[node].word_ids.push_back(id);
    }

    void dfs(int r, int c, int node)
    {
        int pos = r * C + c;
        visited[pos] = 1;
        if (!trie[node].word_ids.empty())
        {
            for (int id : trie[node].word_ids)
            {
                if (!found_flag[id])
                {
                    found_flag[id] = 1;
                    found_words.push_back(words[id]);
                }
            }
            trie[node].word_ids.clear();
        }
        static const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int k = 0; k < 8; ++k)
        {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 nr >= R nc < 0 || nc >= C)
                continue;
            int npos = nr * C + nc;
            if (visited[npos])
                continue;
            int nextChar = board[nr][nc] - 'a';
            int nextNode = trie[node].next[nextChar];
            if (nextNode != -1)
                dfs(nr, nc, nextNode);
        }
        visited[pos] = 0;
    }

    vector<string> solve()
    {
        found_flag.assign((int)words.size(), 0);
        visited.assign(R * C, 0);
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
            {
                int idx = board[i][j] - 'a';
                int nextNode = trie[0].next[idx];
                if (nextNode != -1)
                    dfs(i, j, nextNode);
            }
        sort(found_words.begin(), found_words.end());
        return found_words;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, cols;
    if (!(cin >> rows >> cols))
        return 0;
    vector<vector<char>> board(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> board[i][j];

    int num_words;
    cin >> num_words;
    vector<string> words(num_words);
    for (int i = 0; i < num_words; ++i)
        cin >> words[i];

    Solver solver(rows, cols);
    solver.board = move(board);
    solver.words = words;
    for (int i = 0; i < num_words; ++i)
        solver.insert_word(words[i], i);

    vector<string> found = solver.solve();
    if (found.empty())
    {
        cout << "0\n";
    }
    else
    {
        cout << found.size() << "\n";
        for (auto &w : found)
            cout << w << "\n";
    }
    return 0;
}