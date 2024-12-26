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
	if (pat[0] == '\0')
		return NULL;

	int txt_len = strlen(txt);
	int pat_len = strlen(pat);

	for (int i = 0; i <= txt_len - pat_len; i++)
	{
		if (txt[i] == pat[0])
		{
			int j = 0;
			for (j = 1; j < pat_len; j++)
			{
				if (txt[i + j] != pat[j])
				{
					break;
				}
			}
			if (j == pat_len)
				return (char *)(txt + i);
		}
	}
	return NULL;
}