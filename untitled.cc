#include <cstdio>

int main()
{
	freopen("input.txt","r",stdin);
	char s[100];
	while(gets(s))
	{
		for(int i=7;i>=0;i--)
			putchar(s[i]);
		puts("");
	}
}