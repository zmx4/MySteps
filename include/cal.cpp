#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
enum SymbolType
{
	NUMBER,
	OPERATOR,
	BRACKET
};
enum BracketType
{
	LEFT = -1,
	RIGHT = 1
};
class MathSymbol
{
public:
	SymbolType type;
	double value;
};
int getSymbolPriority(MathSymbol symbol)
{
	if (symbol.type == OPERATOR)
	{
		switch ((int)symbol.value)
		{
		case 1: // +
		case 2: // -
			return 1;
		case 3: // *
		case 4: // /
			return 2;
		default:
			return 0;
		}
	}
	return 0;
}
vector<MathSymbol> stringToMathSymbolList(string str)
{
	vector<MathSymbol> result;
	int decimalPlaces = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			if (i > 0)
			{
				if (str[i - 1] >= '0' && str[i - 1] <= '9')
				{
					/*if(isNegative){
					  result[result.size()-1].value = result[result.size()-1].value*10 - str[i] + '0';
					}
					else{
					  result[result.size()-1].value = result[result.size()-1].value + (str[i] - '0')/10;
					}*/
					if (decimalPlaces == 0 && str[i - 1] != '.')
					{
						result[result.size() - 1].value = result[result.size() - 1].value * 10 + (str[i] - '0');
					}
					else
					{
						result[result.size() - 1].value = result[result.size() - 1].value + (str[i] - '0') / pow(10, decimalPlaces - 1);
					}
				}
				else
				{
					MathSymbol symbol;
					symbol.type = NUMBER;
					/*if(isNegative){
					  MathSymbol symbol;

					  symbol.type = NUMBER;

					  symbol.value = -str[i] + '0';

					  result.push_back(symbol);

					}

					else{

					  MathSymbol symbol;

					  symbol.type = NUMBER;

					  symbol.value = str[i] - '0';

					  result.push_back(symbol);

					}*/

					if (decimalPlaces == 0)
					{

						symbol.value = str[i] - '0';

						result.push_back(symbol);
					}

					else
					{

						result[result.size() - 1].value = (str[i] - '0') / pow(10, decimalPlaces - 1);
					}
				}
			}

			else
			{

				MathSymbol symbol;

				symbol.type = NUMBER;

				symbol.value = str[i] - '0';

				result.push_back(symbol);
			}
		}

		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{

			MathSymbol symbol;

			symbol.type = OPERATOR;

			switch (str[i])
			{

			case '+':

				symbol.value = 1;

				break;

			case '-':

				symbol.value = 2;

				break;

			case '*':

				symbol.value = 3;

				break;

			case '/':

				symbol.value = 4;

				break;

			default:

				break;
			}

			decimalPlaces = 0;

			result.push_back(symbol);
		}

		else if (str[i] == '(' || str[i] == ')')
		{

			MathSymbol symbol;

			symbol.type = BRACKET;

			symbol.value = str[i] == '(' ? -1 : 1;

			result.push_back(symbol);

			decimalPlaces = 0;
		}

		else if (str[i] == '.')

		{

			decimalPlaces++;
		}

		if (decimalPlaces != 0)
		{

			decimalPlaces++;
		}
	}

	return result;
}

// 使用栈来计算表达式的值

double calculate(vector<MathSymbol> mathSymbolList)
{

	// 中缀表达式转后缀表达式

	vector<MathSymbol> postfixExpression;

	vector<double> stack;

	for (int i = 0; i < mathSymbolList.size(); i++)
	{

		if (mathSymbolList[i].type == NUMBER)
		{

			postfixExpression.push_back(mathSymbolList[i]);
		}

		else if (mathSymbolList[i].type == OPERATOR)
		{

			while (!stack.empty() && getSymbolPriority(mathSymbolList[i]) <= getSymbolPriority(mathSymbolList[stack.back()]))
			{

				postfixExpression.push_back(mathSymbolList[stack.back()]);

				stack.pop_back();
			}

			stack.push_back(i);
		}

		else if (mathSymbolList[i].type == BRACKET)
		{

			if (mathSymbolList[i].value == LEFT)
			{

				stack.push_back(i);
			}

			else
			{

				while (mathSymbolList[stack.back()].value != LEFT)
				{

					postfixExpression.push_back(mathSymbolList[stack.back()]);

					stack.pop_back();
				}

				stack.pop_back();
			}
		}
	}

	while (!stack.empty())
	{

		postfixExpression.push_back(mathSymbolList[stack.back()]);

		stack.pop_back();
	}

	// 计算后缀表达式的值

	stack.clear();

	for (int i = 0; i < postfixExpression.size(); i++)
	{

		if (postfixExpression[i].type == NUMBER)
		{

			stack.push_back(postfixExpression[i].value);
		}

		else if (postfixExpression[i].type == OPERATOR)
		{

			double b = stack.back();

			stack.pop_back();

			double a = stack.back();

			stack.pop_back();

			switch ((int)postfixExpression[i].value)
			{

			case 1:

				stack.push_back(a + b);

				break;

			case 2:

				stack.push_back(a - b);

				break;

			case 3:

				stack.push_back(a * b);

				break;

			case 4:

				stack.push_back(a / b);

				break;

			default:

				break;
			}
		}
	}

	return stack.back();
}

int main()

{

	string str;

	cin >> str;

	vector<MathSymbol> mathSymbolList = stringToMathSymbolList(str);

	double result = calculate(mathSymbolList);

	cout << result << endl;
}