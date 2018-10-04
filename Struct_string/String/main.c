#include <stdio.h>
#include <string.h>

void standardString(char s[])
{
	int len = strlen(s);
	int i = 0;
	int j;
	while(s[0] == ' ' && len > 0)
	{
		for(i = 0; i < len-1; i++)
		{
			s[i] = s[i+1];
		}
		len--;
	}
	
	while(s[len-1] == ' ' && len > 0)
	{
		s[len-1] = '\0';
		len--;
	}
	
	for(i = 0; i < len; i++)
	{
		if(s[i] == ' ' && s[i+1] == ' ')
		{
			for(j = i; j < len - 1; j++)
			{
				s[j] = s[j+1];
			}
			s[len-1] = '\0';
			len--;
			i--;
		}
	}
	
	if(s[0] >= 'a')
	{
		s[0] -= 32;
	}
	
	for(i = 1; i < len; i++)
	{
		if(s[i-1] == ' ' && s[i] != ' ')
		{
			if(s[i] >= 'a')
			{
				s[i] -= 32;
			}
		}
	}
}

int countWord(char s[])
{
	standardString(s);
	int len = strlen(s);
	printf("\nlen in FUn = %d", len);
	
	int i;
	int count;
	//if no word
	if(len == 0)
	{
		count = 0;
	}
	else
	{
		count = 1;
	}
	for(i = 0; i < len; i++)
	{
		if(s[i] == ' ')
		{
			count++;
		}
	}
	return count;
}

int main()
{
	char s[] = "  ";
	standardString(s);
	printf("%s", s);
	printf("\nNumber of word: %d", countWord(s));
	return 0;
}
