#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int k, m;
    string n_binary;
    cin >> k >> m >> n_binary;

    vector<int> n(k, 0);
    for (int i = 0; i < n_binary.size(); ++i)
    {
        n[k - n_binary.size() + i] = n_binary[i] - '0';
    }

    vector<vector<vector<long long>>> dp(k + 1, vector<vector<long long>>(m + 1, vector<long long>(2, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int c = 0; c <= 1; ++c)
            {
                if (dp[i][j][c] == 0)
                    continue;

                if (n[i] == 0)
                {
                    if (j + c <= m)
                    {
                        dp[i + 1][j + c][0] = (dp[i + 1][j + c][0] + dp[i][j][c]) % MOD;
                    }

                    if (j + c <= m)
                    {
                        dp[i + 1][j + c][1] = (dp[i + 1][j + c][1] + dp[i][j][c]) % MOD;
                    }
                }
                else
                {
                    int new_ones = (1 + c) % 2;
                    int new_carry = (1 + c) / 2;

                    if (j + new_ones <= m)
                    {
                        dp[i + 1][j + new_ones][new_carry] = (dp[i + 1][j + new_ones][new_carry] + 2 * dp[i][j][c]) % MOD;
                    }
                }
            }
        }
    }

    long long result = (dp[k][m][0] + dp[k][m][1]) % MOD;

    bool is_n_zero = true;
    for (int bit : n)
    {
        if (bit == 1)
        {
            is_n_zero = false;
            break;
        }
    }
    if (!is_n_zero)
    {
        result = (result * ((MOD + 1) / 2)) % MOD;
    }

    cout << result << endl;
    return 0;
}