#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1e5;
const int INF = 1e9;

vector<pii> G[MAXN];
int dist[MAXN], vis[MAXN];

void dijkstra(int x)
{
    for(int i = 0; i < MAXN; i++) dist[i] = INF, vis[i] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, x});

    while(!q.empty())
    {
        int v = q.top().second;
        q.pop();

        if(vis[v]) continue;
        vis[v] = true;

        for(pair<int, int> a : G[v])
        {
            int u = a.first, w = a.second;

            if(dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                q.push({dist[u], u});
            }
        }
    }
}

int main()
{

}
