#include <bits/stdc++.h>
using namespace std;

#define MID ((l + r)/2)

struct node
{
	node *left, *right;

	int sum;

	node()
	{
		left = right = nullptr;
		sum = 0;
	}
};

void update(node* prev, node* cur, int pos, int val, int l, int r)
{
	if(l == r) cur->sum = val;

	else
	{
		if(prev->right == nullptr) prev->right = new node();
		if(prev->left == nullptr) prev->left = new node();

		if(pos <= MID)
		{
			cur->right = prev->right;

			cur->left = new node();

			update(prev->left, cur->left, pos, val, l, MID);
		}
		else
		{
			cur->left = prev->left;

			cur->right = new node();

			update(prev->right, cur->right, pos, val, MID + 1, r);
		}
		cur->sum = cur->left->sum + cur->right->sum;
	}
}

int query(node* cur, int a, int b, int l, int r)
{
	if(l >= a and r <= b) return cur->sum;

	if(b <= MID) return query(cur->left, a , b, l, MID);
	else if(a > MID) return query(cur->right, a, b, MID + 1, r);

	int leftQuery = query(cur->left, a, b, l, MID);
	int rightQuery = query(cur->right, a, b, MID + 1, r);

	return leftQuery + rightQuery;
}

node* ver[100101];

int main()
{

}
