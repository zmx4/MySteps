#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Tree
{
	char c;
	Tree *l = nullptr;
	Tree *r = nullptr;
};

string strm, strh;
int cnt = 0;

Tree *dfs(string strm, string strh, int inStart, int inEnd)
{
	if (inStart > inEnd)
	{
		return nullptr;
	}

	char rootChar = strh[cnt++];
	Tree *root = new Tree();
	root->c = rootChar;

	int inIndex = -1;
	for (int i = inStart; i <= inEnd; ++i)
	{
		if (strm[i] == rootChar)
		{
			inIndex = i;
			break;
		}
	}

	root->l = dfs(strm, strh, inStart, inIndex - 1);
	root->r = dfs(strm, strh, inIndex + 1, inEnd);

	return root;
}

void dfscout(Tree *t)
{
	if (t == nullptr)
	{
		return;
	}

	dfscout(t->l); 
	dfscout(t->r); 
	cout << t->c;  
}

int main()
{
	cin >> strm >> strh;
	cnt = 0;
	Tree *root = dfs(strm, strh, 0, strm.length() - 1);
	dfscout(root);
	cout << endl;
	return 0;
}