#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
	string val;
	Node *left;
	Node *right;
	Node(string v) : val(v), left(nullptr), right(nullptr) {}
};

bool isOperator(const string &s)
{
	return s == "+" || s == "-" || s == "*" || s == "/";
}

int main()
{
	string input;
	getline(cin, input);
	// 如果存在空格，按空格分割，否则按字符处理
	istringstream iss(input);
	stack<Node *> st;
	string token;
	bool hasSpace = (input.find(" ") != string::npos);

	if (hasSpace)
	{
		// 按空格分割
		while (iss >> token)
		{
			if (!isOperator(token))
			{
				st.push(new Node(token));
			}
			else
			{
				Node *right = st.top();
				st.pop();
				Node *left = st.top();
				st.pop();
				Node *node = new Node(token);
				node->left = left;
				node->right = right;
				st.push(node);
			}
		}
	}
	else
	{
		// 如果没有空格，每个字符为一个token
		for (char ch : input)
		{
			string s(1, ch);
			if (!isOperator(s))
			{
				st.push(new Node(s));
			}
			else
			{
				Node *right = st.top();
				st.pop();
				Node *left = st.top();
				st.pop();
				Node *node = new Node(s);
				node->left = left;
				node->right = right;
				st.push(node);
			}
		}
	}

	// 最终的根结点
	Node *root = st.top();

	// 层次遍历
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		Node *cur = q.front();
		q.pop();
		cout << cur->val << " ";
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	cout << endl;
	return 0;
}