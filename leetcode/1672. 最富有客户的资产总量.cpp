class Solution
{
public:
	int maximumWealth(vector<vector<int>> &accounts)
	{
		int res = 0;
		for (auto &account : accounts)
		{
			int sum = 0;
			for (auto &money : account)
			{
				sum += money;
			}
			res = std::max(res, sum);
		}
		return res;
	}
};