#include <bits/stdc++.h>
using namespace std;
#define N 3

struct Node
{
	Node* parent;
	int mat[N][N];
	int x, y;
	int cost;
	int level;
};

int inMaTran(int mat[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

Node* newNode(int mat[N][N], int x, int y, int newX,
			int newY, int level, Node* parent)
{
	Node* node = new Node;
	node->parent = parent;
	memcpy(node->mat, mat, sizeof node->mat);
	swap(node->mat[x][y], node->mat[newX][newY]);
	node->cost = INT_MAX;
	node->level = level;
	node->x = newX;
	node->y = newY;
	return node;
}

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

int vitridung(int initial[N][N], int final[N][N])
{
	int count = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		if (initial[i][j] && initial[i][j] != final[i][j])
		count++;
	return count;
}

int antoan(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void Xuat(Node* root)
{
	if (root == NULL)
		return;
	Xuat(root->parent);
	inMaTran(root->mat);

	printf("\n");
}

struct sosanh
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
	}
};

void AKT(int initial[N][N], int x, int y,
		int final[N][N])
{
	priority_queue<Node*, vector<Node*>, sosanh> pq;
	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = vitridung(initial, final);
	pq.push(root);
	while (!pq.empty())
	{
		Node* min = pq.top();
		pq.pop();
		if (min->cost == 0)
		{
			Xuat(min);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if (antoan(min->x + row[i], min->y + col[i]))
			{
				Node* child = newNode(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->level + 1, min);
				child->cost = vitridung(child->mat, final);
				pq.push(child);
			}
		}
	}
}

int main()
{
	int bandau[N][N] =
	{
		{1, 2, 3},
		{5, 0, 6},
		{7, 8, 4}
	};
	int ketthuc[N][N] =
	{
		{1, 2, 3},
		{5, 8, 6},
		{0, 7, 4}
	};
	int x = 1, y = 1;
	AKT(bandau, x, y, ketthuc);

	return 0;
}

