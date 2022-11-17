#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
vector<int> G[MAXN];

bool vis[MAXN];

void dfs(int x) {
    vis[x] = true;
    for(int u : G[x]) if(!vis[u]) dfs(u);
}

void bfs(int x) {
    queue<int> q;
    q.push(x);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if(vis[v]) continue;
        vis[v] = true;

        for(int u : G[v]) q.push(u);
    }
}

