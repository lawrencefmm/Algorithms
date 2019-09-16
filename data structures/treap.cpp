#include <bits/stdc++.h>
using namespace std;

mt19937 rd(random_device{}());
struct node
{
	int v, w;
	node *l, *r;

	node(int v_ = 0)
	{
		v = v_;
		l = r = nullptr;
		w = rd();
	}
};

// merge two nodes
void merge(node *&t, node *a, node *b)
{
	if(a == nullptr or b == nullptr)
		t = a ? a : b;

	else if(a -> w >= b -> w)
		merge(a->r, a->r , b), t = a;

	else
		merge(b->l, a, b->l), t = b;
}

//split a treap into two,
void split(node *t, node *&a, node *&b, int k)
{
	if(t == nullptr)
		a = b = nullptr;

	else if(t -> v < k)
		a = t, split(t->r, t->r, b, k);

	else
		b = t, split(t->l, a, t->l, k);
}

bool find(node *t, int v)
{
	if(t == nullptr) return false;
	if(t -> v == v) return true;
	if(t -> v > v) return find(t->l, v);
	else return find(t->r, v);
}

void insert(node *&t, int v)
{
	if(find(t, v)) return;

	node *a = nullptr, *b = nullptr, *aux = new node(v);

	split(t, a, b, v);
	merge(a, a, aux);
	merge(t, a, b);
}

void split_insert(node *&t, node *a)
{
	if(t == nullptr)
		t = a;

	else if(t -> w < a -> w)
		split(t, a -> l, a -> r, a -> v), t = a;

	else
		split_insert(a -> v < t -> v ? t -> l : t -> r, a);
}

void erase(node *&t, int v)
{
	if(!find(t, v)) return;

	node *a = nullptr, *b = nullptr, *aux = nullptr;

	split(t, a, b, v);
	split(b, aux, b, v + 1);
	merge(t, a, b);
	delete aux;
}

void print(node *t)
{
	if(t == nullptr) return;

	print(t -> l);
	cout << t -> v << " ";
	print(t -> r);
}
