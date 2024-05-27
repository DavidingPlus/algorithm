#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Node {
public:
	Node *lch, *rch;
	int t;
	int h;
	int k, v;
};

Node *recs = 0;

void recyle(Node *rec)
{
	rec->lch = recs;
	recs = rec;
}

Node *createNode()
{
	if (recs)
	{
		Node *ret = recs;
		recs = ret->lch;
		return ret;
	}
	return new Node;
}

int getT(Node *node)
{
	return (node)?node->t:0;
}

void updateT(Node *node)
{
	node->t = getT(node->lch) + getT(node->rch) + 1;
}

int get(Node *root, int k)
{
	if (!root)
		return -1;
	if (root->k == k)
		return root->v;
	if (root->k > k)
		return get(root->lch, k);
	return get(root->rch, k);
}

void insert(Node *&root, int k, int v)
{
	if (!root)
	{
		root = createNode();
		root->lch = root->rch = 0;
		root->t = 1;
		root->h = rand();
		root->k = k;
		root->v = v;
		return ;
	}
	if (root->k == k)
	{
		root->v = v;
		return ;
	}
	if (root->k > k)
	{
		insert(root->lch, k, v);
		if (root->lch->h < root->h)
		{
			Node *ll = root->lch;
			root->lch = ll->rch;
			ll->rch = root;
			root = ll;
			updateT(root->rch);
		}
		updateT(root);
	}
	else
	{
		insert(root->rch, k, v);
		if (root->rch->h < root->h)
		{
			Node *rr = root->rch;
			root->rch = rr->lch;
			rr->lch = root;
			root = rr;
			updateT(root->lch);
		}
		updateT(root);
	}
}

Node *merge(Node *a, Node *b)
{
	if (!a) return b;
	if (!b) return a;
	if (a->h < b->h)
	{
		a->rch = merge(a->rch, b);
		updateT(a);
		return a;
	}
	else
	{
		b->lch = merge(a, b->lch);
		updateT(b);
		return b;
	}
}

int dodel(Node *&root, int k)
{
	if (!root)
		return 0;
	int ret = 0;
	if (root->k == k)
	{
		ret = getT(root->rch);
		Node *rec = root;
		root = merge(root->lch, root->rch);
		recyle(rec);
		return ret;
	}
	if (root->k > k)
		ret = getT(root->rch) + 1 + dodel(root->lch, k);
	else
		ret = dodel(root->rch, k);
	updateT(root);
	return ret;
}

Node *proot = 0;
Node *rroot = 0;

void printT(Node *r)
{
	if (!r) return ;
	printf("(");
	if (r->lch)
		printT(r->lch);
	printf("%d[%d] ", r->k, r->t);
	if (r->rch)
		printT(r->rch);
	printf(")");
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		int p = get(proot, x);
		if (p < 0)
		{
			printf("-%d ", x);
		}
		else
		{
			int v = dodel(rroot, p);
			printf("%d ", v);
		}
		insert(proot, x, i);
		insert(rroot, i, x);
	}
	printf("\n");
	return 0;
}
