#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_in_lo(char** withoutPhrase, char** withPhrase, int wwop, int wwp)
{
	// lo
	int i, j;
	char t[30] = "";
	//strncpy(t, " ", 1);
	for (i = 0; i < wwop; i++)
	{
		for (j = 0; j < wwop - 1; j++)
		{
			if (strcmp(withoutPhrase[i], withoutPhrase[j + 1]) > 0)
			{
				strncpy(t, withoutPhrase[j + 1], strlen(withoutPhrase[j + 1]));
				strncpy(withoutPhrase[j+1], withoutPhrase[i], strlen(withoutPhrase[i]));
				strncpy(withoutPhrase[i], t, strlen(t));
			}
		}
	}

	for (i = 0; i < wwp; i++)
	{
		for (j = 0; j < wwp - 1; j++)
		{
			if (strcmp(withPhrase[i], withPhrase[j + 1]) > 0)
			{
				strncpy(t, withPhrase[j + 1], strlen(withPhrase[j + 1]));
				strncpy(withPhrase[j + 1], withPhrase[i], strlen(withPhrase[i]));
				strncpy(withPhrase[i], t, strlen(t));
			}
		}
	}

	// print

	printf("Amount of words without phrase: %d\nWithout phrase:\n", wwop);
	for (i = 0; i < wwop; i++)
	{
		printf("%s\n", withoutPhrase[i]);
	}
	printf("With phrase:\n");
	for (i = 0; i < wwp; i++)
	{
		printf("%s\n", withPhrase[i]);
	}
}

void search_phrase(char* src, char* phr)
{
	int src_l = strlen(src);
	char src_str[30] = "";
	//int tmp = 0;
	//strncpy(src_str, " ", 1);

	int wc = 0;

	int i; char* j;
	int lb = 0, rb = 0; // left border, right border

	for (i = 0; i <= src_l; i++)
	{
		if (isspace(src[i]))
		{
			wc++; // word count
		}
	}

	int wwop = 0;
	int wwp = 0;

	char** withoutPhrase = (char**)malloc(wc * sizeof(char*));
	char** withPhrase = (char**)malloc(wc * sizeof(char*));

	for (i = 0; i <= src_l; i++)
	{
		if (isspace(src[i]))
		{
			strncpy(src_str, "", 1);
			strncpy(src_str, src + lb, rb - lb); // rb-lb - length of word
			j = strstr(src_str, phr);
			if (j == NULL)
			{
				//tmp = rb-lb+1;
				withoutPhrase[wwop] = (char*)malloc((rb - lb + 1) * sizeof(char));
				strncpy(withoutPhrase[wwop], "", 1);
				strncpy(withoutPhrase[wwop], src_str, rb - lb);

				wwop++;
			}
			else {
				withPhrase[wwp] = (char*)malloc((rb - lb + 1) * sizeof(char));
				strncpy(withoutPhrase[wwp], "", 1);
				strncpy(withoutPhrase[wwp], src_str, rb - lb);

				wwp++;
			}

			rb++;
			lb = rb;
		}
		else {
			rb++;
		}
	}

	print_in_lo(withoutPhrase, withPhrase, wwop, wwp);//lexicographical order
}

int main()
{
	/*char src[100] = "";

	printf("Enter str: ");
	fgets(src, )*/

	char phr[15] = "";
	char src[] = "All difficulty estimating unreserved increasing the solicitude"; //re, All difficulty estimating unreserved increasing the solicitude

	printf("Enter phrase: ");
	scanf_s("%s", phr, 15);

	search_phrase(src, phr);

	system("pause");
	return 0;
}
