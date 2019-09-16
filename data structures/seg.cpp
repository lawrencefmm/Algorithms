#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

#define LEFT (2*node)
#define RIGHT ((2*node) + 1)
#define MID ((l + r)/2)

int tree[3*maxn], v[maxn];

int op(int a, int b)
{
	return a + b;
}

void build(int node, int l, int r)
{
	if(l == r) tree[node] = v[l];

	else
	{
		build(LEFT, l, MID);
		build(RIGHT, MID + 1, r);

		tree[node] = op(tree[LEFT], tree[RIGHT]);
	}
}

int query(int node, int l, int r, int a, int b)
{
	if(a <= l and r <= b) return tree[node];

    if(b <= MID) return query(LEFT, l, MID, a, b);
    else if(a > MID) return query(RIGHT, MID + 1, r, a, b);

	int queryLeft = query(LEFT, l, MID, a, b);
	int queryRight = query(RIGHT, MID + 1, r, a, b);

	return queryLeft + queryRight;
}

void update(int node, int l, int r, int pos, int val)
{
	if(l == r) tree[node] = v[l] = val;

	else
	{
		if(pos <= MID) update(LEFT, l, MID, pos, val);
		else update(RIGHT, MID + 1, r, pos, val);

		tree[node] = op(tree[LEFT], tree[RIGHT]);
	}
}
