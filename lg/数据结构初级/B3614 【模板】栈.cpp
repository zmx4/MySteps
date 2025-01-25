#include <iostream>
#include <vector>
#include <string>
#define uint64_t unsigned long long
class Stack
{
private:
	std::vector<uint64_t> stack;

public:

	void push(uint64_t x)
	{
		stack.push_back(x);
	}

	void pop()
	{
		if (stack.empty())
		{
			std::cout << "Empty" << std::endl;
		}
		else
		{
			stack.pop_back();
		}
	}

	void query()
	{
		if (stack.empty())
		{
			std::cout << "Anguei!" << std::endl;
		}
		else
		{
			std::cout << stack.back() << std::endl;
		}
	}

	void size()
	{
		std::cout << stack.size() << std::endl;
	}
};

int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		int n;
		std::cin >> n;
		Stack s;
		for (int i = 0; i < n; ++i)
		{
			std::string operation;
			std::cin >> operation;
			if (operation == "push")
			{
				uint64_t x;
				std::cin >> x;
				s.push(x);
			}
			else if (operation == "pop")
			{
				s.pop();
			}
			else if (operation == "query")
			{
				s.query();
			}
			else if (operation == "size")
			{
				s.size();
			}
		}
	}
	return 0;
}