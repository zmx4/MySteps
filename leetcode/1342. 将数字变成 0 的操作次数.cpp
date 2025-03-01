class Solution
{
public:
	int numberOfSteps(int num)
	{
		if (num == 0)
			return 0;
		std::bitset<32> b(num);
		int res = 0;
		bool flag = false;
		for (int i = 31; i >= 0; i--)
		{
			if (!flag && b[i])
			{
				flag = true;
				res++;
			}
			else if (flag)
			{
				if (b[i])
					res += 2;
				else
					res++;
			}
		}
		return res;
	}
};