#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400;
const int INF = 1e8;

int dist[MAXN][MAXN];
int G[MAXN][MAXN];

void floyd_warshall()
{
    for(int i = 0; i < MAXN; i++)
    {
        for(int j = 0; j < MAXN; j++)
        {
            if(i == j) dist[i][j] = 0;
            else if(G[i][j]) dist[i][j] = G[i][j];
            else dist[i][j] = dist[j][i] = INF;
        }
    }

    for(int k = 0; k < MAXN; k++)
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
