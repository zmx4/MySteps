#include <iostream>
#include <cstring>
using namespace std;
string A, B;
char s1[2005], s2[2005]; // s1=A , s2=B
int edit[2005][2005];
int dp(int i, int j)
{
    if (edit[i][j] != -1)
        return edit[i][j];
    if (i == 0)
        return edit[i][j] = j;
    if (j == 0)
        return edit[i][j] = i;
    int bonus = 1;
    if (s1[i] == s2[j])
        bonus = 0;
    return edit[i][j] = min(min(dp(i - 1, j) + 1, dp(i, j - 1) + 1), dp(i - 1, j - 1) + bonus);
}
int main()
{
    cin >> A >> B;
    memset(edit, -1, sizeof(edit));
    int len1 = A.length(), len2 = B.length();
    for (int i = 1; i <= len1; i++)
        s1[i] = A[i - 1]; // 将字符串转成cstring
    for (int i = 1; i <= len2; i++)
        s2[i] = B[i - 1];
    dp(len1, len2);
    cout << edit[len1][len2];
    return 0;
}
