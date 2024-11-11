#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

void dfs(Node* head, set<Node*>& visited, vector<int>& result) {
    if (head == nullptr || visited.find(head) != visited.end()) {
        return;
    }
    visited.insert(head);
    result.push_back(head->val);
    dfs(head->next, visited, result);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int>mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[i+1] = a[i];
        a[i]--; 
    }
    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(i + 1);
    }
    
    for(int i = 0; i < n; i++) {
        nodes[i]->next = nodes[a[i]];
    }
    for(int i = 0; i < n; i++) {
        vector<int> result;
        set<Node*> visited;
        dfs(nodes[i], visited, result);
        cout <<mp[result.back()] << " "; 
    }    
    return 0;
}