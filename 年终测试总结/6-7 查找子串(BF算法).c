#include <stdio.h>
#include <string.h>

char *StrStr(const char *txt, const char *pat);

int main()
{
	char m[1024], s[1024], *p;
	gets(m);
	gets(s);
	p = StrStr(m, s);
	if (p)
	{
		printf("%d\n", p - m);
	}
	else
	{
		puts("NULL");
	}
	return 0;
}
char *StrStr(const char *txt, const char *pat)
{
	int cnt = 0;
	int index = -1;
	for (int i = 0; i < strlen(txt); i++)
	{
		if (txt[i] = pat[0])
		{
			int sign = 0;
			for (int j = 1; j < strlen(pat); j++)
			{
				if (txt[i + j] != pat[j])
				{
					sign = 1;
				}
			}
			if (!sign)
			{
				if (cnt == 0)
					index = i;
				cnt++;
			}
		}
	}
	if (cnt == 0)
		return NULL;
	else
	{
		return (char *)*txt + index;
	}
}