#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct tree
{
	char c;
	tree *l = nullptr, *r = nullptr; // Initialize pointers to nullptr
};

string strm, strh;
int cnt = 0;

tree *dfs(string str)
{
	if (str.empty())
	{
		return nullptr; // Base case: empty string, return nullptr
	}

	tree *t = new tree(); // Allocate a new node

	t->c = strh[cnt++]; // Assign the current character from strh to the node

	size_t p0 = str.find(t->c); // Find the position of the character in strm
	if (p0 == string::npos)
	{
		delete t;
		return nullptr;
	}

	if (p0 > 0)
	{
		t->l = dfs(str.substr(0, p0));
	}
	else
	{
		t->l = nullptr;
	}

	if (p0 < str.length() - 1)
	{
		t->r = dfs(str.substr(p0 + 1));
	}
	else
	{
		t->r = nullptr;
	}
	return t;
}

void dfscout(tree *t)
{
	if (t)
	{
		if (t->l)
		{
			dfscout(t->l);
		}
		cout << t->c;
		if (t->r)
		{
			dfscout(t->r);
		}
	}
}

void deleteTree(tree *t)
{
	if (t)
	{
		deleteTree(t->l);
		deleteTree(t->r);
		delete t;
	}
}

int main()
{
	cin >> strm >> strh;

	tree *root = dfs(strm);
	dfscout(root);
	cout << endl;

	deleteTree(root);
	return 0;
}