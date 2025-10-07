#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mem(10, vector<int>(1<<10, -1));
class Solution
{
public:
    int size;
    vector<int> digits;
    int numDupDigitsAtMostN(int n)
    {
        return n - solve(n);
    }

    int solve(int n)
    {
        digits.clear();
        while (n)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        size = digits.size();
        return dfs(0, 0, true, true);
    }

    int dfs(int n ,int mark, bool limit, bool lead)
    { 
        if (n == size)
            return lead ? 0 : 1;
        if (!limit && !lead && mem[size - n][mark] != -1)
            return mem[size - n][mark];
        int res = 0;
        int up = limit ? digits[n] : 9;
        for (int i = 0; i <= up; i++)
        {
            if ((mark & (1 << i)) == 0)
                res += dfs(n + 1, (lead && (i == 0) ? mark : mark | (1 << i)), limit && i == up, lead && i == 0);
        }
        if (!limit && !lead)
            mem[size - n][mark] = res;
        return res;
    }
};